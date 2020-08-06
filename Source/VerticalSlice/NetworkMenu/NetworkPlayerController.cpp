// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkPlayerController.h"
#include "VerticalSlice/VerticalSliceCharacter.h"
#include "Engine/World.h"

ANetworkPlayerController::ANetworkPlayerController()
{

}

void ANetworkPlayerController::BeginPlay()
{
	Super::BeginPlay();

}



void ANetworkPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ANetworkPlayerController::SetupInputComponent()
{
}

void ANetworkPlayerController::TravelBackToHubWorld(APawn * InstigatorPawn)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Levels/HubWorld?listen");
}

void ANetworkPlayerController::TravelToSpringLevel(APawn* InstigatorPawn)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Levels/SpringRevised?listen");
}

void ANetworkPlayerController::TravelToAutumnLevel(APawn* InstigatorPawn)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Levels/AutumnRevised?listen");
}

void ANetworkPlayerController::TravelToWinterLevel(APawn* InstigatorPawn)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Levels/WinterRevised?listen");
}

void ANetworkPlayerController::TravelToSummerLevel(APawn* InstigatorPawn)
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Levels/SummerRevised?listen");
}
