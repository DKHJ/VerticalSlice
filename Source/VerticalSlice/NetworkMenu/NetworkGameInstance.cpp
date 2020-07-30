// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include "OnlineSessionSettings.h"
#include "OnlineSubsystemTypes.h"

#include "NetworkMainMenu.h"

const static FName SESSION_NAME = TEXT("Game");
const static FName SERVER_NAME_SETTINGS_KEY = TEXT("ServerName");

UNetworkGameInstance::UNetworkGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/UI/Widgets/NetworkMainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

}

void UNetworkGameInstance::Init()
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid()) {
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UNetworkGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UNetworkGameInstance::OnCreateSessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UNetworkGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UNetworkGameInstance::OnJoinSessionComplete);
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found no subsystem"));
	}
}

void UNetworkGameInstance::LoadMenuWidget()
{
	if (!ensure(MenuClass != nullptr)) return;

	NetworkMenu = CreateWidget<UNetworkMainMenu>(this, MenuClass);
	if (!ensure(NetworkMenu != nullptr)) return;

	NetworkMenu->Setup();

	NetworkMenu->SetNetworkMenuInterface(this);
}

void UNetworkGameInstance::Host(FString ServerName)
{
	DesiredServerName = ServerName;
	if (SessionInterface.IsValid())
	{
		auto ExistingSession = SessionInterface->GetNamedSession(SESSION_NAME);
		if (ExistingSession != nullptr)
		{
			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			CreateSession();
		}
	}
}

void UNetworkGameInstance::Join(uint32 Index)
{
	if (!SessionInterface.IsValid()) return;
	if (!SessionSearch.IsValid()) return;

	if (NetworkMenu != nullptr)
	{
		NetworkMenu->Teardown();
	}

	SessionInterface->JoinSession(0, SESSION_NAME, SessionSearch->SearchResults[Index]);
}

void UNetworkGameInstance::StartSession()
{
	if (SessionInterface.IsValid())
	{
		SessionInterface->StartSession(SESSION_NAME);
	}
}

void UNetworkGameInstance::LoadNetworkMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/Levels/NetworkMainMenu", ETravelType::TRAVEL_Absolute);
}

void UNetworkGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid())
	{
		//SessionSearch->bIsLanQuery = true;
		SessionSearch->MaxSearchResults = 1000;
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
		UE_LOG(LogTemp, Warning, TEXT("Starting Find Session"));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UNetworkGameInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{
	if (!Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session"));
		return;
	}

	if (NetworkMenu != nullptr)
	{
		NetworkMenu->Teardown();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Levels/WinterRevised?listen");
}

void UNetworkGameInstance::OnDestroySessionComplete(FName SessionName, bool Success)
{
	if (Success) {
		CreateSession();
	}
}

void UNetworkGameInstance::OnFindSessionsComplete(bool Success)
{
	if (Success && SessionSearch.IsValid() && NetworkMenu != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Finished Find Session"));

		TArray<FServerData> ServerNames;
		for (const FOnlineSessionSearchResult& SearchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found session names: %s"), *SearchResult.GetSessionIdStr());
			FServerData Data;
			Data.MaxPlayers = SearchResult.Session.SessionSettings.NumPublicConnections;
			Data.CurrentPlayers = Data.MaxPlayers - SearchResult.Session.NumOpenPublicConnections;
			Data.HostUsername = SearchResult.Session.OwningUserName;
			FString ServerName;
			if (SearchResult.Session.SessionSettings.Get(SERVER_NAME_SETTINGS_KEY, ServerName))
			{
				Data.Name = ServerName;
			}
			else
			{
				Data.Name = "Could not find name.";
			}
			ServerNames.Add(Data);
		}

		NetworkMenu->SetServerList(ServerNames);
	}
}

void UNetworkGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (!SessionInterface.IsValid()) return;

	FString Address;
	if (!SessionInterface->GetResolvedConnectString(SessionName, Address)) {
		UE_LOG(LogTemp, Warning, TEXT("Could not get connect string."));
		return;
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	Engine->AddOnScreenDebugMessage(0,5, FColor::Green, FString::Printf(TEXT("Is Client")));
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UNetworkGameInstance::CreateSession()
{
	if (SessionInterface.IsValid()) {
		FOnlineSessionSettings SessionSettings;
		if (IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
		{
			SessionSettings.bIsLANMatch = true;
		}
		else
		{
			SessionSettings.bIsLANMatch = false;
		}
		SessionSettings.NumPublicConnections = 2;
		SessionSettings.bShouldAdvertise = true;
		SessionSettings.bUsesPresence = true;
		SessionSettings.Set(SERVER_NAME_SETTINGS_KEY, DesiredServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

		SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
	}
}
