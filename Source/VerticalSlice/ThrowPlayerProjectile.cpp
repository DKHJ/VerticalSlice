// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowPlayerProjectile.h"

// Sets default values
AThrowPlayerProjectile::AThrowPlayerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThrowPlayerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThrowPlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

