// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerRune.h"

// Sets default values
ATimerRune::ATimerRune()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimerRune::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimerRune::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimerRune::DoInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("C++ Called TimerRune DoInteract()!"));
}

