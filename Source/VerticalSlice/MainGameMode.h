// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMainGameMode();

	class ABaseInteract* FindInteractiveById(const FName& ID) const;

protected:

	virtual void BeginPlay() override;

private:
	TArray<class ABaseInteract*> InteractiveInLevelList;

private:
	void GetInteractivesInLevel();
};
