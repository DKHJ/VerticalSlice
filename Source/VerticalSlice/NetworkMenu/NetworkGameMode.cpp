// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "VerticalSlice/VerticalSlice.h"
#include "VerticalSlice/VerticalSliceCharacter.h"
#include "VerticalSlice/Interactable/BaseInteract.h"
#include "UObject/ConstructorHelpers.h"

ANetworkGameMode::ANetworkGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Blueprints/Characters/BP_BigCharacter"));
	DefaultPawnClass = PlayerPawnOb.Class;

	static ConstructorHelpers::FClassFinder<APawn> SmallCharOb(TEXT("/Game/Blueprints/Characters/BP_SmallCharacter"));
	SmallCharClass = SmallCharOb.Class;

	PlayerControllerClass = ANetworkPlayerController::StaticClass();

}
void ANetworkGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ANetworkPlayerController* NewPC = Cast<ANetworkPlayerController>(NewPlayer);
	if (NewPC && NewPC->GetPawn() == NULL)
	{
		//NewPC->Spawn
	}
}

void ANetworkGameMode::RestartPlayer(AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);

	ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(NewPlayer);

	if (PC)
	{
		AVerticalSliceCharacter*Character = Cast<AVerticalSliceCharacter>(PC->GetCharacter());
		if (Character)
		{
			
		}
	}
}

AActor * ANetworkGameMode::ChoosePlayerStart_Implementation(AController * Player)
{
	return nullptr;
}

bool ANetworkGameMode::ShouldSpawnAtStartSpot(AController * Player)
{
	return false;
}

UClass * ANetworkGameMode::GetDefaultPawnClassForController_Implementation(AController * InController)
{
	return nullptr;
}

ANetworkGameMode::ANetworkGameMode()

{

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

void ANetworkGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetInteractivesInLevel();
}

bool ANetworkGameMode::IsSpawnpointAllowed(APlayerStart * SpawnPoint, AController * Player) const
{
	return false;
}

bool ANetworkGameMode::IsSpawnpointPreferred(APlayerStart * SpawnPoint, AController * Player) const
{
	return false;
}

void ANetworkGameMode::GetInteractivesInLevel()
{
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
