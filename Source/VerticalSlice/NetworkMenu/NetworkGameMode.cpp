// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "VerticalSlice/VerticalSlice.h"
#include "VerticalSlice/VerticalSliceCharacter.h"
#include "VerticalSlice/Interactable/BaseInteract.h"
#include "UObject/ConstructorHelpers.h"


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
