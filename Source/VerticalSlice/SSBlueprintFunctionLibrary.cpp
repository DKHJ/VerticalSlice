// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBlueprintFunctionLibrary.h"

void USSBlueprintFunctionLibrary::DisableSplitScreen(AActor* Context, bool bDisable)
{
	if (Context)
	{
		Context->GetWorld()->GetGameViewport()->SetDisableSplitscreenOverride(bDisable);
	}
}

void USSBlueprintFunctionLibrary::SetEnableSplitscreen(const UObject* WorldContextObject, bool bEnable)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		UGameViewportClient* GameViewportClient = World->GetGameViewport();
		if (GameViewportClient)
		{
			GameViewportClient->SetDisableSplitscreenOverride(!bEnable);
		}
	}
}

bool USSBlueprintFunctionLibrary::GetEnableSplitscreen(const UObject* WorldContextObject)
{
	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		UGameViewportClient* GameViewportClient = World->GetGameViewport();
		if (GameViewportClient)
		{
			return !GameViewportClient->GetDisableSplitscreenOverride();
		}
	}
	return false;
}