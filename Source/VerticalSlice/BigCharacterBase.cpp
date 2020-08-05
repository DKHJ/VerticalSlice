// Fill out your copyright notice in the Description page of Project Settings.


#include "BigCharacterBase.h"

void ABigCharacterBase::DoInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("BigCharacterBase Called Event DoInteract()!"));
	if (CurrentInteractActorReference)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("BigCharacterBase Called Event DoInteract() on its Reference!"));
		
	}
	if (CurrentInteractInterface)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("BigCharacterBase Called Event DoInteract() on its Interact Interface!"));
	}
	
}