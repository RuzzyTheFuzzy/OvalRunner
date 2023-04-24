// Fill out your copyright notice in the Description page of Project Settings.


#include "ObsticleSpawner.h"

// Sets default values
AObsticleSpawner::AObsticleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void AObsticleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObsticleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::RandRange(0,30) == 30)
	{
		GetWorld()->SpawnActor<AObsticle>(Obsticle, FVector(0,FMath::RandRange(-3000,3000),10),FRotator());
	}

}

