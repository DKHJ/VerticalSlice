// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteract.h"
#include "VerticalSlice/MainGameMode.h"
#include "Components/BoxComponent.h"
#include "VerticalSlice/BigCharacterBase.h"
#include "VerticalSlice/VerticalSliceGameMode.h"
#include "VerticalSlice/NetworkMenu/NetworkGameMode.h"

// Sets default values
ABaseInteract::ABaseInteract()
{
	// Overwrite the default actor root component, with our scene root component
	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	// Create a Mesh object and attatch it to the scene component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	// Create our Collision Box and attach it to the scene component
	InteractCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractCollisionBox"));
	InteractCollisionBox->SetupAttachment(RootComponent);

	// Dynamic events
	InteractCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseInteract::BeginOverlap);
	InteractCollisionBox->OnComponentEndOverlap.AddDynamic(this, &ABaseInteract::EndOverlap);

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
	ANetworkGameMode* GM = Cast<ANetworkGameMode>(GetWorld()->GetAuthGameMode());

	if (GM == nullptr) return nullptr;


	ABaseInteract* interactive = GM->FindInteractiveById(ConnectedInteractiveID);

	return interactive;
	

	
}

void ABaseInteract::SendSignalToInteractive()
{
	UE_LOG(LogTemp, Warning, TEXT("ABasicInteractive::SendSignalToInteractive called"));
}

/** Overlap Event ( Should ideally only be characters ) */
void ABaseInteract::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("C++ Called ABaseInteract BeginOverlap  Event!"));

	if (CharacterReference != nullptr) return;

	auto Character = Cast<AVerticalSliceCharacter>(OtherActor);
	// Check if we're overlapping with a valid character
	if (Character)
	{
		CharacterReference = Character;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Checking interface!"));
		IInteractionInterface* Interface = Cast<IInteractionInterface>(CharacterReference);
		if (Interface)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("true interface!"));
			CharacterReference->CurrentInteractActorReference = this;
		}
		

		//IInteractionInterface* Interface = Cast<IInteractionInterface>(CharacterReference);
		//// Check for a valid interface on the character reference
		//if (Interface)
		//{
		//	Interface->DoInteract();
		//}
	}
}

void ABaseInteract::EndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	auto Character = Cast<AVerticalSliceCharacter>(OtherActor);
	if (Character)
	{
		if ((CharacterReference != nullptr) && (CharacterReference == Character))
		{
			// Release the overlapped character reference
			CharacterReference = nullptr;

			IInteractionInterface* Interface = Cast<IInteractionInterface>(CharacterReference);

			if (Interface)
			{
				SetOwner(nullptr);

				//// Notifies the interface
				//Interface->NotifyLeaveInteractRange(this);
			}
		}
	}
}

// Called every frame
void ABaseInteract::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
