// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteract.h"
#include "VineBridge.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API AVineBridge : public ABaseInteract
{
	GENERATED_BODY()
	
public:

	AVineBridge();

protected:

	virtual void BeginPlay() override;


protected:

	UPROPERTY(ReplicatedUsing = OnRep_IsVisibleChanged, EditDefaultsOnly, Category = "VineBridge")
		bool bIsVisible = false;

	UFUNCTION()
	void OnRep_IsVisibleChanged();

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerDoActivatedAction();


	void DoActivatedAction();


	UFUNCTION(BlueprintImplementableEvent)
		void onActivatedVineBridgeEvent();

public:
	virtual void StartInteracting(APawn* PawnInstigator) override;

	virtual void SendSignalToInteractive() override;
};
