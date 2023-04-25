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

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	TSubclassOf<AObsticle> Obsticle;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	FVector2D YSpawnRange;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	FVector StartingMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	float SpeedIncrease;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	float ObjectsPerSecIncrease;

	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	float ObjectsPerSecond;
	
	UPROPERTY(EditDefaultsOnly, Category = "Obstacles")
	float XDistanceObstacleRespawn;

	UPROPERTY(VisibleAnywhere, Category = "Obstacles")
	FVector CurrentMovement;

	// I really dont get pointers ok? Is this correct?
	TArray<TObjectPtr<AObsticle>> ReuseObstacles;

	float Timer;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddToReusePile(AObsticle* Obstacle);
};
