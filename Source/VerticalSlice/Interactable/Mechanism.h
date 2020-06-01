// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteract.h"
#include "Mechanism.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API AMechanism : public ABaseInteract
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Mechanism")
		bool isActivated = false;


	void DoActivatedAction();

	UFUNCTION(BlueprintImplementableEvent)
		void onMechanismActivatedEvent();

public:
	virtual void StartInteracting(APawn* PawnInstigator) override;
	
};
