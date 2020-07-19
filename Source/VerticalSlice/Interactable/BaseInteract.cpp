// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteract.h"
#include "VerticalSlice/MainGameMode.h"
#include "Components/BoxComponent.h"
#include "VerticalSlice/BigCharacterBase.h"
#include "VerticalSlice/VerticalSliceGameMode.h"

// Sets default values
ABaseInteract::ABaseInteract()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMesh"));
	Mesh->SetupAttachment(RootComponent);

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);

	// Dynamic events
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseInteract::BeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseInteract::EndOverlap);


	//Mark the interactive as replicates
	SetReplicates(true);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseInteract::BeginPlay()
{
	Super::BeginPlay();

}



void ABaseInteract::StartInteracting(APawn * PawnInstigator)
{
	UE_LOG(LogTemp, Warning, TEXT("ABasicInteractive::StartInteracting called"));
}

ABaseInteract * ABaseInteract::GetConnectedInteractive()
{
	if (ConnectedInteractiveID == "NONE") return nullptr;

	UE_LOG(LogTemp, Warning, TEXT("Not Connected"));
	AMainGameMode * GM = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	if (GM == nullptr) return nullptr;


	ABaseInteract* interactive = GM->FindInteractiveById(ConnectedInteractiveID);

	return interactive;
	

	
}

void ABaseInteract::SendSignalToInteractive()
{
	UE_LOG(LogTemp, Warning, TEXT("ABasicInteractive::SendSignalToInteractive called"));
}

void ABaseInteract::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("ABasicInteractive::Overllaping called"));
	if (CharacterOverlapping != nullptr) return;

	auto Character = Cast<AVerticalSliceCharacter>(OtherActor);
	if (Character)
	{
		CharacterOverlapping = Character;

		// Detects if  the interface CharacterOverlapping
		IInteractionInterface* Interface = Cast<IInteractionInterface>(CharacterOverlapping);

		if (Interface)
		{
			SetOwner(CharacterOverlapping);

			// Notify the interface with this interactive
			Interface->NotifyInInteractRange(this);
		}
	}
}

void ABaseInteract::EndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	auto Character = Cast<AVerticalSliceCharacter>(OtherActor);
	if (Character)
	{
		if ((CharacterOverlapping != nullptr) && (CharacterOverlapping == Character))
		{
			// Release the overlapped character reference
			CharacterOverlapping = nullptr;

			IInteractionInterface* Interface = Cast<IInteractionInterface>(CharacterOverlapping);

			if (Interface)
			{
				SetOwner(nullptr);

				// Notifies the interface
				Interface->NotifyLeaveInteractRange(this);
			}
		}
	}
}

// Called every frame
void ABaseInteract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
