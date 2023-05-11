// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obsticle.h"
#include "GameFramework/Actor.h"
#include "ObsticleSpawner.generated.h"

UCLASS()
class OVALRUNNER_API AObsticleSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObsticleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	TSubclassOf<AObsticle> Obsticle;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	FVector2D YSpawnRange;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	FVector StartingMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	float SpeedIncrease;

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	float ObjectsPerSecIncrease;

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	float ObjectsPerSecond;
	
	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	float XDistanceObstacleRespawn;

	UPROPERTY(VisibleAnywhere, Category = "Obstacles")
	FVector CurrentMovement;

	UPROPERTY()
	TArray<TObjectPtr<AObsticle>> ReuseObstacles;

	UPROPERTY()
	TArray<TObjectPtr<AObsticle>> SpawnedObstacles;

	float Timer;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
