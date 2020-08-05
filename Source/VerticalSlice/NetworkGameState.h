// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "NetworkGameState.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API ANetworkGameState : public AGameState
{
	GENERATED_BODY()

		
public:

	//This runs on server and client
	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnLevelCompleted(APawn* InstigatorPawn);

	UFUNCTION(Server, Reliable)
	void ServerOnLevelCompleted(APawn* InstigatorPawn);

protected:

	//Bools for specific levels, do not need to be persistent, in game state.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCog1PickedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCog2PickedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCog3PickedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSummerPuzzlePart1Complete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSummerPuzzlePart2Complete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSummerPuzzlePartComplete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CogsPickedUp;


};
