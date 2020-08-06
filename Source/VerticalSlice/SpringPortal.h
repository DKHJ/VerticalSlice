// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpringPortal.generated.h"

UCLASS()
class VERTICALSLICE_API ASpringPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpringPortal();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringPortal", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RootScene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringPortal", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpringPortal", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* Collision;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

UFUNCTION()
void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool ToSpringLevel;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool ToWinterLevel;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool ToSummerLevel;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool ToAutumnLevel;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool ToHubWorld;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool BigCharacterPresent;

	UPROPERTY(Replicated, EditDefaultsOnly, Category = "Portal")
		bool SmallCharacterPresent;


private:

	
};
