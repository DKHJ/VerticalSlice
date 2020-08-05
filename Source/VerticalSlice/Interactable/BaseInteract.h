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
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interactive", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* Collision;


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

	class AVerticalSliceCharacter* CharacterOverlapping = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FName ConnectedInteractiveID;

};
