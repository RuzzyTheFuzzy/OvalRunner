// Fill out your copyright notice in the Description page of Project Settings.

// TODO: Learn to spell and maybe rename everything correctly


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveComponent.h"
#include "Obsticle.generated.h"

UCLASS()
class OVALRUNNER_API AObsticle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObsticle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	TObjectPtr<UMoveComponent> MovementComponent;

	double RespawnXDistance;
	double StartXPos;

	// I am truly sorry for this monster
	TObjectPtr<TArray<TObjectPtr<AObsticle>>> ReuseArray;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetMovementSpeed(FVector NewMovement);

	void SetRespawnDistance(double XDistance);

	void SetReuseArray(TObjectPtr<TArray<TObjectPtr<AObsticle>>> Array);
};
