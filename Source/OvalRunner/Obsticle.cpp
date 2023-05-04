// Fill out your copyright notice in the Description page of Project Settings.


#include "Obsticle.h"

// Sets default values
AObsticle::AObsticle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	SetRootComponent(StaticMeshComponent);

	MovementComponent = CreateDefaultSubobject<UMoveComponent>("Movement Component");
}

// Called when the game starts or when spawned
void AObsticle::BeginPlay()
{
	Super::BeginPlay();

	StartXPos = GetActorLocation().X;
}

// Called every frame
void AObsticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMath::Abs(StartXPos - GetActorLocation().X) > RespawnXDistance)
	{
		if (!this->IsHidden() && ReuseArray != nullptr) // Cause i care about safety
		{
			this->SetActorHiddenInGame(true);
			ReuseArray->Add(this);
		}
	}
}

void AObsticle::SetMovementSpeed(FVector NewMovement)
{
	MovementComponent->SetMovement(NewMovement);
}

void AObsticle::SetRespawnDistance(double XDistance)
{
	RespawnXDistance = XDistance;
}

void AObsticle::SetReuseArray(TObjectPtr<TArray<TObjectPtr<AObsticle>>> Array)
{
	if (ReuseArray == nullptr)
	{
		ReuseArray = Array;
	}
}
