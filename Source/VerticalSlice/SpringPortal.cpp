// Fill out your copyright notice in the Description page of Project Settings.


#include "SpringPortal.h"

// Sets default values
ASpringPortal::ASpringPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpringPortal::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpringPortal::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void ASpringPortal::TravelToSpring()
{
}

// Called every frame
void ASpringPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

