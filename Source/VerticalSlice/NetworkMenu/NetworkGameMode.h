// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetworkPlayerController.h"
#include "GameFramework/GameMode.h"
#include "NetworkGameMode.generated.h"

class APlayerStart;
/**
 * 
 */
UCLASS()
class VERTICALSLICE_API ANetworkGameMode : public AGameMode
{
	GENERATED_BODY()


	//virtual void PostLogin(APlayerController* NewPlayer) override;

	//virtual void RestartPlayer(AController* NewPlayer) override;

	/** select best spawn point for player */
	//virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	/** always pick new random spawn */
	//virtual bool ShouldSpawnAtStartSpot(AController* Player) override;

	/** returns default pawn class for given controller */
	//virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
public:

	//ANetworkGameMode();

	class ABaseInteract* FindInteractiveById(const FName& ID) const;

protected:

	//virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	virtual void BeginPlay() override;

	/** check if player can use spawnpoint */
//	virtual bool IsSpawnpointAllowed(APlayerStart* SpawnPoint, AController* Player) const;

	/** check if player should use spawnpoint */
	//virtual bool IsSpawnpointPreferred(APlayerStart* SpawnPoint, AController* Player) const;

	//virtual UClass* GetDefaultPawnForController_Implementation(AController* InController) override;

private:
	TArray<class ABaseInteract*> InteractiveInLevelList;

private:
	void GetInteractivesInLevel();
};
