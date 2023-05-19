// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Movement = FVector(1, 0, 0);
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	this->GetOwner()->AddActorWorldOffset(DeltaTime * Movement, CheckForCollision);
}

void UMoveComponent::SetMovement(FVector NewMovement)
{
	Movement = NewMovement;
}

FVector UMoveComponent::GetMovement() const
{
	return Movement;
}
