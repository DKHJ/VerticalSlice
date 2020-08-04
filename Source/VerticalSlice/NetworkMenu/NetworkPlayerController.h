// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NetworkPlayerController.generated.h"


UCLASS()
class VERTICALSLICE_API ANetworkPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	



public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Controller")
	void OnLevelComplete(APawn* InstigatorPawn);

};
