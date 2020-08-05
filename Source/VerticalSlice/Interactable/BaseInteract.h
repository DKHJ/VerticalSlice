// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "BaseInteract.generated.h"

UCLASS()
class VERTICALSLICE_API ABaseInteract : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseInteract();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactions", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Mesh;

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactions", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* InteractCollisionBox;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void StartInteracting(APawn* PawnInstigator);

	virtual ABaseInteract* GetConnectedInteractive();

	virtual void SendSignalToInteractive();

	// Daniel
	virtual void Interact() PURE_VIRTUAL(AMster_Interactable::Interact, );

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class AVerticalSliceCharacter* CharacterReference = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FName ConnectedInteractiveID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USceneComponent* _RootComponent;
	


};
