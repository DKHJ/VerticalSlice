// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SSBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API USSBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Viewport")
		static void DisableSplitScreen(AActor* Context, bool bDisable);

	/**
	 * Enabled Splitscreen
	 * @param	bEnable		Whether the viewport should splitscreen between local players or not
	 */
	UFUNCTION(BlueprintCallable, Category = "Viewport", meta = (WorldContext = "WorldContextObject"))
		static void SetEnableSplitscreen(const UObject* WorldContextObject, bool bEnable);

	/**
	 * Returns the Splitscreen state
	 * @return	Whether the game viewport is splitscreen or not
	 */
	UFUNCTION(BlueprintPure, Category = "Viewport", meta = (WorldContext = "WorldContextObject"))
		static bool GetEnableSplitscreen(const UObject* WorldContextObject);
};
