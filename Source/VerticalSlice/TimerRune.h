// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable/BaseInteract.h"
#include "InteractionInterface.h"
#include "TimerRune.generated.h"

UCLASS()
class VERTICALSLICE_API ATimerRune : public ABaseInteract, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerRune();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame

	virtual void Tick(float DeltaTime) override;
	virtual void DoInteract() override;
	
};
