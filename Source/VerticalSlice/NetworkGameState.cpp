// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameState.h"
#include "NetworkMenu/NetworkPlayerController.h"


void ANetworkGameState::ServerTravelToSpring_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(It->Get());

		if (PC && PC->IsLocalController())

		{
			PC->TravelToSpringLevel(InstigatorPawn);
		}

	}
}

void ANetworkGameState::ServerTravelToAutumn_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(It->Get());

		if (PC && PC->IsLocalController())

		{
			PC->TravelToAutumnLevel(InstigatorPawn);
		}

	}
}

void ANetworkGameState::ServerTravelToWinter_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(It->Get());

		if (PC && PC->IsLocalController())

		{
			PC->TravelToWinterLevel(InstigatorPawn);
		}

	}
}

void ANetworkGameState::ServerTravelToSummer_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(It->Get());

		if (PC && PC->IsLocalController())

		{
			PC->TravelToSummerLevel(InstigatorPawn);
		}

	}
}

void ANetworkGameState::ServerBackToHubWorld_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(It->Get());

		if (PC && PC->IsLocalController())

		{
			PC->TravelBackToHubWorld(InstigatorPawn);
		}

	}
}

