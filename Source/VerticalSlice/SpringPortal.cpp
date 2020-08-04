// Fill out your copyright notice in the Description page of Project Settings.


#include "SpringPortal.h"
#include "NetworkMenu/NetworkGameMode.h"
#include "NetworkMenu/NetworkPlayerController.h"
#include "VerticalSliceCharacter.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASpringPortal::ASpringPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCount = 0;
}

// Called when the game starts or when spawned
void ASpringPortal::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpringPortal::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVerticalSliceCharacter* Pawn = Cast<AVerticalSliceCharacter>(OtherActor);

	if (Pawn == nullptr)
	{
		return;
	}

	PlayerCount++;

	if (PlayerCount >= 2)
	{
		UWorld* World = GetWorld();
		if (World == nullptr)
		{
			return;
		}

		ANetworkGameMode* GameMode = Cast<ANetworkGameMode>(World->GetAuthGameMode());

		if (GameMode == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("[ASpringPortal::HandleOverlap] GameMode NULL"));
			return;
		}

		if (GameMode != nullptr)
		{
			GameMode->CompletedLevel(Pawn, true);
		}
	}
}


void ASpringPortal::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASpringPortal, PlayerCount);
}
void ASpringPortal::TravelToSpring()
{
}

// Called every frame
void ASpringPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

