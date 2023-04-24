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

	UPROPERTY(EditDefaultsOnly, Category = "Obsticles")
	TSubclassOf<AObsticle> Obsticle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
