// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class OVALRUNNER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	TObjectPtr<UMoveComponent> MovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Despawn")
	float DespawnTime;

	float Timer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetMovement(FVector Movement) const;

};
