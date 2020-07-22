// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetworkPlayerController.h"
#include "GameFramework/GameMode.h"
#include "NetworkGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API ANetworkGameMode : public AGameMode
{
	GENERATED_BODY()


	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void RestartPlayer(AController* NewPlayer) override;

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
