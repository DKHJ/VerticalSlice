// Fill out your copyright notice in the Description page of Project Settings.


#include "WinterRune.h"

AWinterRune::AWinterRune()
{


}
void AWinterRune::BeginPlay()
{
	Super::BeginPlay();
}

void AWinterRune::DoActivatedAction()
{
	bisActivated = true;
}



void AWinterRune::StartInteracting(APawn * PawnInstigator)
{
	Super::StartInteracting(PawnInstigator);

	if (bisActivated)
	{
		UE_LOG(LogTemp, Warning, TEXT("[AWinterRune::StartInteracting] bisActivated ==  we can go in"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[AWinterRune::StartInteracting] bisActivated == false we can go in"));
	}
}

void AWinterRune::SendSignalToInteractive()
{
	UE_LOG(LogTemp, Warning, TEXT("[AWinterRune::SendSignalToInteractive] "));

	Super::SendSignalToInteractive();

	if (!bisActivated)
	{
		UE_LOG(LogTemp, Warning, TEXT("[AWinterRune::SendSignalToInteractive] !bisActivated"));
		DoActivatedAction();
	}
}
