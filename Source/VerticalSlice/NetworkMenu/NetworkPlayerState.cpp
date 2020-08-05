// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkPlayerState.h"
#include "Net/UnrealNetwork.h"



void ANetworkPlayerState::ClientInitialize(AController * InController)
{
}

void ANetworkPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps)const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ANetworkPlayerState, PlayerNumber);
}