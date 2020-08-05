// Fill out your copyright notice in the Description page of Project Settings.


#include "WinterPillar.h"


AWinterPillar::AWinterPillar()
{

}
void AWinterPillar::BeginPlay()
{
	Super::BeginPlay();
}

void AWinterPillar::DoActivatedAction()
{
	bisActivated = true;

	onActivatedWinterPillarEvent();
}

//void AWinterPillar::StartInteracting(APawn * PawnInstigator)
//{
//	Super::StartInteracting(PawnInstigator);
//
//	if (bisActivated)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("[AWinterPillar::StartInteracting] bisActivated = true"));
//	}
//	else
//	{
//		UE_LOG(LogTemp, Warning, TEXT("[AWinterPillar::StartInteracting] bisActivated == false"));
//	}
//}
//
//void AWinterPillar::SendSignalToInteractive()
//{
//	UE_LOG(LogTemp, Warning, TEXT("[AWinterRune::SendSignalToInteractive] "));
//
//	Super::SendSignalToInteractive();
//
//	if (!bisActivated)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("[AWinterRune::SendSignalToInteractive] !bisActivated"));
//		DoActivatedAction();
//	}
//}
