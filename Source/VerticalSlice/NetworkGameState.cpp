// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameState.h"
#include "NetworkMenu/NetworkPlayerController.h"


void ANetworkGameState::MulticastOnLevelCompleted_Implementation(APawn* InstigatorPawn)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ANetworkPlayerController* PC = Cast<ANetworkPlayerController>(It->Get());

		if (PC && PC->IsLocalController())
		{
			PC->OnLevelCompleted(InstigatorPawn);
		}
	}
}
