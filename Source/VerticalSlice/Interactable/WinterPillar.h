// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseInteract.h"
#include "WinterPillar.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API AWinterPillar : public ABaseInteract
{
	GENERATED_BODY()
	
public:
	AWinterPillar();

protected:

	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditAnywhere, Category = "WinterPillar")
		bool bisActivated = false;

	void DoActivatedAction();


	UFUNCTION(BlueprintImplementableEvent)
		void onActivatedWinterPillarEvent();

public:
	//virtual void StartInteracting(APawn* PawnInstigator) override;
	//virtual void SendSignalToInteractive() override;
};
