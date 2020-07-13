// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NetworkMenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNetworkMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VERTICALSLICE_API INetworkMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
public:
	virtual void Host(FString ServerName) = 0;

	virtual void Join(uint32 Index) = 0;
	virtual void LoadNetworkMainMenu() = 0;
	virtual void RefreshServerList() = 0;
};
