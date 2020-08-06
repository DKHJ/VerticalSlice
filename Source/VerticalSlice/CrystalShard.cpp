// Fill out your copyright notice in the Description page of Project Settings.


#include "CrystalShard.h"
#include "Components/BoxComponent.h" 


// Sets default values
ACrystalShard::ACrystalShard()
{

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainMesh"));
	Mesh->SetupAttachment(RootComponent);

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);

	// Dynamic events
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ACrystalShard::BeginOverlap);
	


	//Mark the interactive as replicates
	SetReplicates(true);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
 	

}

// Called when the game starts or when spawned
void ACrystalShard::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACrystalShard::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

// Called every frame
void ACrystalShard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

