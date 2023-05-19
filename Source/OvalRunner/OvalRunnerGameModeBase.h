// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SaveScore.h"
#include "GameFramework/GameModeBase.h"
#include "OvalRunnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class OVALRUNNER_API AOvalRunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<USaveScore> SaveScoreInstance;

	UPROPERTY()
	FString SaveSlot = "SaveSlot";
	int UserIndex = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Main Menu")
	FName LevelToLoad;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health", meta = (AllowPrivateAccess = "true", ClampMin = 1))
	uint8 PlayerHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	float CurrentScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
	float HighScore;

public:
	AOvalRunnerGameModeBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void DamagePlayer();
};
