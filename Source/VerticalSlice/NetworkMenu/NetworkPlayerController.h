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
	ANetworkPlayerController();

	virtual void BeginPlay() override;


protected:

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

protected:

	class AVerticalSliceCharacter* myCharacter;


public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Controller")
	void OnLevelComplete(APawn* InstigatorPawn);

	UFUNCTION()
	void TravelBackToHubWorld(APawn* InstigatorPawn);

	UFUNCTION()
	void TravelToSpringLevel(APawn* InstigatorPawn);

	UFUNCTION()
	void TravelToAutumnLevel(APawn* InstigatorPawn);

	UFUNCTION()
	void TravelToWinterLevel(APawn* InstigatorPawn);
	
	UFUNCTION()
	void TravelToSummerLevel(APawn* InstigatorPawn);
};
