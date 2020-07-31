// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vines.generated.h"

UCLASS()
class VERTICALSLICE_API AVines : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVines();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(ReplicatedUsing = OnRep_IsVisibleChanged, EditDefaultsOnly, Category = "Vine")
		bool isVisible = false;

	UFUNCTION()
	void OnRep_IsVisibleChanged();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
