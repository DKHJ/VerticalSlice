// Fill out your copyright notice in the Description page of Project Settings.


#include "VineBridge.h"
#include "Net/UnrealNetwork.h"

AVineBridge::AVineBridge()
{
}


void AVineBridge::BeginPlay()
{
	Super::BeginPlay();
}

void AVineBridge::OnRep_IsVisibleChanged()
{
	onActivatedVineBridgeEvent();
	
}
	
	

void AVineBridge::DoActivatedAction()
{
	bIsVisible = true;
	onActivatedVineBridgeEvent();
	OnRep_IsVisibleChanged();
}



void AVineBridge::StartInteracting(APawn * PawnInstigator)
{
	Super::StartInteracting(PawnInstigator);

	if (bIsVisible)
	{
		UE_LOG(LogTemp, Warning, TEXT("[AVineBridge::StartInteracting] bIsVisible ==  we can go across"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[AVineBridge::StartInteracting] bIsOpen == false we cant go across"));
	}
}

void AVineBridge::SendSignalToInteractive()
{
	UE_LOG(LogTemp, Warning, TEXT("[AVineBridge::SendSignalToInteractive] "));

	Super::SendSignalToInteractive();

	if (!bIsVisible)
	{
		UE_LOG(LogTemp, Warning, TEXT("[AVineBridge::SendSignalToInteractive] !bIsOpen"));

		// We need to check if we are server or not
		if (GetLocalRole() < ROLE_Authority)
		{
			ServerDoActivatedAction();
		}
		else
		{
			DoActivatedAction();
		}
	}
}

void AVineBridge::ServerDoActivatedAction_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("[AVineBridge::ServerDoActivatedAction_Implementation]"));

	DoActivatedAction();
}

bool AVineBridge::ServerDoActivatedAction_Validate()
{
	return true;
}

void AVineBridge::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AVineBridge, bIsVisible);
}