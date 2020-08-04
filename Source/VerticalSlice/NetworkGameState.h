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

	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnLevelCompleted(APawn* InstigatorPawn);
};
