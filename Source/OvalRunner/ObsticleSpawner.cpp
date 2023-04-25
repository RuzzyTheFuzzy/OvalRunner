// Fill out your copyright notice in the Description page of Project Settings.


#include "ObsticleSpawner.h"

// Sets default values
AObsticleSpawner::AObsticleSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	YSpawnRange = FVector2D(-1000, 1000);
	SpeedIncrease = 1;
	StartingMovement = FVector(100, 0, 0);
	ObjectsPerSecond = 1;
	ObjectsPerSecIncrease = 0.1;
	XDistanceObstacleRespawn = 5000;
}

// Called when the game starts or when spawned
void AObsticleSpawner::BeginPlay()
{
	Super::BeginPlay();

	CurrentMovement = StartingMovement;
}

// Called every frame
void AObsticleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer -= DeltaTime;

	if (Timer <= 0)
	{
		FVector Position = GetActorLocation();

		Position.Y += FMath::RandRange(YSpawnRange.X, YSpawnRange.Y);

		if (ReuseObstacles.IsEmpty())
		{
			AObsticle* NewObsticle = GetWorld()->SpawnActor<AObsticle>(Obsticle, Position, FRotator());

			NewObsticle->SetMovementSpeed(CurrentMovement);
			NewObsticle->SetReuseArray(&ReuseObstacles);
			NewObsticle->SetRespawnDistance(XDistanceObstacleRespawn);
		}
		else
		{
			ReuseObstacles[0]->SetActorLocation(Position);
			ReuseObstacles[0]->SetMovementSpeed(CurrentMovement);
			ReuseObstacles[0]->SetActorHiddenInGame(false);
			ReuseObstacles.RemoveAt(0);
		}

		Timer = 1 / ObjectsPerSecond; // By using OPS its easier to increase spawn speed linearly
	}

	CurrentMovement += CurrentMovement.GetSafeNormal() * (SpeedIncrease * DeltaTime);

	ObjectsPerSecond += ObjectsPerSecIncrease * DeltaTime;
}

void AObsticleSpawner::AddToReusePile(AObsticle* Obstacle)
{
	ReuseObstacles.Add(Obstacle);
}
