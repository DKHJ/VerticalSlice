// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "VerticalSliceCharacter.h"
#include "VerticalSlice/Interactable/BaseInteract.h"
#include "VerticalSlice.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AMainGameMode::AMainGameMode()
{

}

ABaseInteract * AMainGameMode::FindInteractiveById(const FName & ID) const
{
	for (int32 i = 0; i < InteractiveInLevelList.Num(); i++)
	{
		if (InteractiveInLevelList[i]->ID == ID)
		{
			UE_LOG(LogTemp, Warning, TEXT("[AMainGameMode::FindInteractiveById] Interactive: %s "), *InteractiveInLevelList[i]->GetName());

			return InteractiveInLevelList[i];
		}
	}

	return nullptr;
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetInteractivesInLevel();
}

void AMainGameMode::GetInteractivesInLevel()
{
	TArray<AActor*> Objects;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseInteract::StaticClass(), Objects);
	for (int32 i = 0; i < Objects.Num(); i++)
	{
		ABaseInteract* Interactive = Cast<ABaseInteract>(Objects[i]);
		if (Interactive != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("[AMainGameMode::GetInteractivesInRoom] Interactive: %s "), *Interactive->GetName());

			InteractiveInLevelList.Add(Interactive);
		}
		UE_LOG(LogTemp, Warning, TEXT("[AMainGameMode::GetInteractablesInRoom] InteractableList Num: %i "), InteractiveInLevelList.Num());
	}
}