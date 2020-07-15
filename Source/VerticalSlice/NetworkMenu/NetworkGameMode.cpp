// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkGameMode.h"


#include "UObject/ConstructorHelpers.h"

UClass* ANetworkGameMode::GetDefaultPawnClassForController(AController* InController)
{
	return nullptr;
}

ANetworkGameMode::ANetworkGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)

{
	/*
	
	
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/BP_BigCharacter"));

	if (PlayerPawnBPClass.Class != NULL)

	{
		DefaultPawnClass = PlayerPawnBPClass.Class;

	}

	
	*/
	// set default pawn class to our Blueprinted character

}

/*
void ANetworkGameMode::PostLogin(APlayerController* NewPlayer)
{

}

*/

