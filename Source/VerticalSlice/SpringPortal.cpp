// Fill out your copyright notice in the Description page of Project Settings.


#include "SpringPortal.h"
#include "Components/BoxComponent.h"
#include "NetworkMenu/NetworkGameMode.h"
#include "NetworkMenu/NetworkPlayerController.h"
#include "VerticalSliceCharacter.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ASpringPortal::ASpringPortal()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ASpringPortal::HandleOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ASpringPortal::OnOverlapEnd);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BigCharacterPresent = false;
	SmallCharacterPresent = false;
}

// Called when the game starts or when spawned
void ASpringPortal::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASpringPortal::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	AVerticalSliceCharacter* Pawn = Cast<AVerticalSliceCharacter>(OtherActor);

	if (Pawn == nullptr)
	{
		return;
	}

	if (OtherActor->ActorHasTag("BigCharacter") == true)
	{
		BigCharacterPresent = false;
	}

	if (OtherActor->ActorHasTag("SmallCharacter") == true)
	{
		SmallCharacterPresent = false;
	}
}

void ASpringPortal::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AVerticalSliceCharacter* Pawn = Cast<AVerticalSliceCharacter>(OtherActor);

	if (Pawn == nullptr)
	{
		return;
	}

	if (OtherActor->ActorHasTag("BigCharacter") == true)
	{
		BigCharacterPresent = true;
	}

	if (OtherActor->ActorHasTag("SmallCharacter") == true)
	{
		SmallCharacterPresent = true;
	}

	if (SmallCharacterPresent && BigCharacterPresent == true)
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
			if (ToSpringLevel == true)
			{
				//GoToCinematicMode();
				GameMode->GoToSpringLevel(Pawn, true);
			
			
			}

			
			else if (ToAutumnLevel == true)
			{
				//GoToCinematicMode();
				GameMode->GoToAutumnLevel(Pawn, true);
			}
			else if (ToSummerLevel == true)
			{
				//GoToCinematicMode();
				GameMode->GoToSummerLevel(Pawn, true);
			}
			else if (ToWinterLevel == true)
			{
				//GoToCinematicMode();
				GameMode->GoToWinterLevel(Pawn, true);
			}

			else if (ToHubWorld == true)
			{
				GameMode->GoToHubWorld(Pawn, true);
			}
		
		}
	}

}


void ASpringPortal::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASpringPortal, BigCharacterPresent);
	DOREPLIFETIME(ASpringPortal, SmallCharacterPresent);
	DOREPLIFETIME(ASpringPortal, ToSpringLevel);
	DOREPLIFETIME(ASpringPortal, ToSummerLevel);
	DOREPLIFETIME(ASpringPortal, ToWinterLevel);
	DOREPLIFETIME(ASpringPortal, ToAutumnLevel);
	DOREPLIFETIME(ASpringPortal, ToHubWorld);
//	DOREPLIFETIME(ASpringPortal, SequenceAsset);


}



// Called every frame
void ASpringPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

