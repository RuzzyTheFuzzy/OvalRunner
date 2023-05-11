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
	AObsticle();

protected:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	TObjectPtr<UMoveComponent> MovementComponent;

public:
	void SetMovementSpeed(FVector NewMovement) const;
};
