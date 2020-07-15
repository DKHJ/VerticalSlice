// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NetworkGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API ANetworkGameMode : public AGameMode
{
	GENERATED_BODY()




public:

	ANetworkGameMode();



	//void PostLogin(APlayerController* NewPlayer) override;

private:
	//uint32 NumberOfPlayers = 0;
};
