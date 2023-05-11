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

public:
	AOvalRunnerGameModeBase();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<USaveScore> SaveScoreInstance;

	UPROPERTY()
	FString SaveSlot = "SaveSlot";
	int UserIndex = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Main Menu")
	FName LevelToLoad;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	float CurrentScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	float HighScore;

	void FinishGame();
};
