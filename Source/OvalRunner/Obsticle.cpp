// Fill out your copyright notice in the Description page of Project Settings.


#include "Obsticle.h"

// Sets default values
AObsticle::AObsticle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	StaticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MovementComponent = CreateDefaultSubobject<UMoveComponent>("Movement Component");
}

// Called when the game starts or when spawned
void AObsticle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObsticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObsticle::SetMovementSpeed(FVector NewMovement)
{
	MovementComponent->SetMovement(NewMovement);
}
