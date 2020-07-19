// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NetworkGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API ANetworkGameMode : public AGameMode
{
	GENERATED_BODY()




public:

	ANetworkGameMode();

	class ABaseInteract* FindInteractiveById(const FName& ID) const;

protected:
	virtual void BeginPlay() override;

	

private:
	TArray<class ABaseInteract*> InteractiveInLevelList;

private:
	void GetInteractivesInLevel();
};
