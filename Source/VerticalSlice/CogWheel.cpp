// Fill out your copyright notice in the Description page of Project Settings.


#include "CogWheel.h"

// Sets default values
ACogWheel::ACogWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACogWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACogWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

