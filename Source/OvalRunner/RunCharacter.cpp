// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ARunCharacter::ARunCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TreadmillComponent = CreateDefaultSubobject<UMoveComponent>("Treadmill Movement");
	
}

// Called when the game starts or when spawned
void ARunCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARunCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARunCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	const APlayerController* PlayerController = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* PlayerEnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	PlayerEnhancedInput->BindAction(InputJump, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	PlayerEnhancedInput->BindAction(InputJump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	PlayerEnhancedInput->BindAction(InputMove, ETriggerEvent::Triggered, this, &ARunCharacter::Move);
	PlayerEnhancedInput->BindAction(InputLook, ETriggerEvent::Triggered, this, &ARunCharacter::Look);
}

void ARunCharacter::Move(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2d MoveDir = Value.Get<FVector2d>();
		const FRotator PlayerRotation(0, Controller->GetControlRotation().Yaw, 0);

		// Forward/Backward direction
		if (MoveDir.Y != 0.f)
		{
			// Get forward vector
			const FVector Direction = PlayerRotation.RotateVector(FVector::ForwardVector);

			AddMovementInput(Direction, MoveDir.Y);
		}

		// Right/Left direction
		if (MoveDir.X != 0.f)
		{
			// Get right vector
			const FVector Direction = PlayerRotation.RotateVector(FVector::RightVector);

			AddMovementInput(Direction, MoveDir.X);
		}
	}
}

void ARunCharacter::Look(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2D LookDir = Value.Get<FVector2D>();

		if (LookDir.X != 0.f)
		{
			AddControllerYawInput(LookDir.X);
		}

		if (LookDir.Y != 0.f)
		{
			AddControllerPitchInput(LookDir.Y);
		}
	}
}
