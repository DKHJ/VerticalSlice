// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NetworkMenuInterface.h"
#include "NetworkMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API UNetworkMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Setup();

	void Teardown();

	void SetNetworkMenuInterface(INetworkMenuInterface* NetworkMenuInterface);

protected:
	INetworkMenuInterface* NetworkMenuInterface;
	
};
