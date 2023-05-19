// Fill out your copyright notice in the Description page of Project Settings.


#include "Obsticle.h"

// Sets default values
AObsticle::AObsticle()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	SetRootComponent(StaticMeshComponent);

	MovementComponent = CreateDefaultSubobject<UMoveComponent>("Movement Component");
}

void AObsticle::SetMovementSpeed(FVector NewMovement) const
{
	if (MovementComponent != nullptr)
	{
		MovementComponent->SetMovement(NewMovement);
	}
}
