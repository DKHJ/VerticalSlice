// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "VerticalSlice/VerticalSlice.h"
#include "VerticalSlice/VerticalSliceCharacter.h"
#include "VerticalSlice/Interactable/BaseInteract.h"
#include "VerticalSlice/NetworkGameState.h"
#include "NetworkPlayerController.h"
#include "NetworkPlayerState.h"
#include "VerticalSlice/NetworkPlayerStart.h"
#include "UObject/ConstructorHelpers.h"



void ANetworkGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	
}



ANetworkGameMode::ANetworkGameMode()
{

	PlayerControllerClass = ANetworkPlayerController::StaticClass();

	GameStateClass = ANetworkGameState::StaticClass();

	PlayerStateClass = ANetworkPlayerState::StaticClass();
}




ABaseInteract* ANetworkGameMode::FindInteractiveById(const FName& ID) const
{
	for (int32 i = 0; i < InteractiveInLevelList.Num(); i++)
	{
		if (InteractiveInLevelList[i]->ID == ID)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ANetworkGameMode::FindInteractiveById] Interactive: %s "), *InteractiveInLevelList[i]->GetName());

			return InteractiveInLevelList[i];
		}
	}

	return nullptr;
}

//This code only runs on the server, there is no instance of the game mode on the client, only on the server
void ANetworkGameMode::GoToSpringLevel(APawn* InstigatorPawn, bool bSuccess)
{

	if (InstigatorPawn == nullptr) return;


	//Call the portal to change the state of the game and let everyone know the new state
	//we can get the game state from the game mode
	ANetworkGameState* gameState = GetGameState<ANetworkGameState>();

	if (gameState != nullptr)
	{
		gameState->ServerTravelToSpring(InstigatorPawn);
	}

}
//This code only runs on the server, there is no instance of the game mode on the client, only on the server
void ANetworkGameMode::GoToAutumnLevel(APawn* InstigatorPawn, bool bSuccess)
{
	if (InstigatorPawn == nullptr) return;


	//Call the portal to change the state of the game and let everyone know the new state
	//we can get the game state from the game mode
	ANetworkGameState* gameState = GetGameState<ANetworkGameState>();

	if (gameState != nullptr)
	{
		gameState->ServerTravelToAutumn(InstigatorPawn);
	}

}
//This code only runs on the server, there is no instance of the game mode on the client, only on the server
void ANetworkGameMode::GoToWinterLevel(APawn* InstigatorPawn, bool bSuccess)
{
	if (InstigatorPawn == nullptr) return;


	//Call the portal to change the state of the game and let everyone know the new state
	//we can get the game state from the game mode
	ANetworkGameState* gameState = GetGameState<ANetworkGameState>();

	if (gameState != nullptr)
	{
		gameState->ServerTravelToWinter(InstigatorPawn);
	}

}
//This code only runs on the server, there is no instance of the game mode on the client, only on the server
void ANetworkGameMode::GoToSummerLevel(APawn* InstigatorPawn, bool bSuccess)
{
	if (InstigatorPawn == nullptr) return;


	//Call the portal to change the state of the game and let everyone know the new state
	//we can get the game state from the game mode
	ANetworkGameState* gameState = GetGameState<ANetworkGameState>();

	if (gameState != nullptr)
	{
		gameState->ServerTravelToSummer(InstigatorPawn);
	}

}

void ANetworkGameMode::GoToHubWorld(APawn* InstigatorPawn, bool bSuccess)
{
	if (InstigatorPawn == nullptr) return;


	//Call the portal to change the state of the game and let everyone know the new state
	//we can get the game state from the game mode
	ANetworkGameState* gameState = GetGameState<ANetworkGameState>();

	if (gameState != nullptr)
	{
		gameState->ServerBackToHubWorld(InstigatorPawn);
	}
}

void ANetworkGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetInteractivesInLevel();
}


void ANetworkGameMode::GetInteractivesInLevel()
{
	//Find all objects of basic interactive type
	TArray<AActor*> Objects;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseInteract::StaticClass(), Objects);
	for (int32 i = 0; i < Objects.Num(); i++)
	{
		ABaseInteract* Interactive = Cast<ABaseInteract>(Objects[i]);
		if (Interactive != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ANetworkGameMode::GetInteractivesInRoom] Interactive: %s "), *Interactive->GetName());

			InteractiveInLevelList.Add(Interactive);
		}
		UE_LOG(LogTemp, Warning, TEXT("[ANetworkGameMode::GetInteractablesInRoom] InteractableList Num: %i "), InteractiveInLevelList.Num());
	}
}
