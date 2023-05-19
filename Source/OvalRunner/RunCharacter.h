// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Projectile.h"
#include "GameFramework/Character.h"
#include "RunCharacter.generated.h"

UCLASS()
class OVALRUNNER_API ARunCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMapping;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputJump;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputMove;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputLook;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputShoot;
	
public:
	ARunCharacter();

protected:

	void RespawnCharacter();

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AProjectile> Projectile;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float ProjectileSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float CooldownTime;

	// If below this height, you take damage and respawn
	UPROPERTY(EditDefaultsOnly, Category = "Life")
	float RespawnHeigh;

	// Where to respawn
	UPROPERTY(EditDefaultsOnly, Category = "Life")
	FVector RespawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CameraSettings")
	TObjectPtr<class UCameraComponent> CameraComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Shoot(const FInputActionValue& Value);
};
