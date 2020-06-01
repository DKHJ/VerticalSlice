// Fill out your copyright notice in the Description page of Project Settings.


#include "Mechanism.h"

void AMechanism::DoActivatedAction()
{
	isActivated = true;
	ABaseInteract* interactive = GetConnectedInteractive();

	if (interactive != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[AMechanism::DoActivatedAction] Connected Interactive found called SendSignalToInteractive: %s "), *interactive->GetName());

		interactive->SendSignalToInteractive();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[AMechanism::DoActivatedAction] Connected Interactive not found "));
	}

	// Call the event
	onMechanismActivatedEvent();
}

void AMechanism::StartInteracting(APawn * PawnInstigator)
{
	Super::StartInteracting(PawnInstigator);

	if (isActivated)
	{
		UE_LOG(LogTemp, Warning, TEXT("[AMechanism::StartInteracting] bIsActivated, we can't activated it again"));
		DoActivatedAction();
	}
	else
	{
		DoActivatedAction();
	}
}