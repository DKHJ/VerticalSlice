// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NetworkPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API ANetworkPlayerState : public APlayerState
{
	GENERATED_BODY()


	virtual void ClientInitialize(class AController* InController) override;
};
