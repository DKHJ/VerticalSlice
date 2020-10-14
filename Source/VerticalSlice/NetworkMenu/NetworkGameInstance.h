// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "OnlineSubsystem.h"
#include "Public/Interfaces/OnlineSessionInterface.h"
#include "NetworkMenuInterface.h"

#include "NetworkGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VERTICALSLICE_API UNetworkGameInstance : public UGameInstance, public INetworkMenuInterface
{
	GENERATED_BODY()
	

public:
	UNetworkGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
		void LoadMenuWidget();

	UFUNCTION(Exec)
		void Host(FString ServerName) override;

	UFUNCTION(Exec)
		void Join(uint32 Index) override;

	void StartSession();

	virtual void LoadNetworkMainMenu() override;

	void RefreshServerList() override;

private:

	TSubclassOf<class UUserWidget> MenuClass;

	class UNetworkMainMenu* NetworkMenu;

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void OnFindSessionsComplete(bool Success);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	FString DesiredServerName;
	void CreateSession();


	protected:
	//Booleans for checking if levels have been completed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsSpringCompleted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsSummerCompleted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsWinterCompleted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsAutumnCompleted;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSeenMainMenu;

};
