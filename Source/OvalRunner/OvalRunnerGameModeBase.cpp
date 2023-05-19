// Copyright Epic Games, Inc. All Rights Reserved.


#include "OvalRunnerGameModeBase.h"

#include "Kismet/GameplayStatics.h"

AOvalRunnerGameModeBase::AOvalRunnerGameModeBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

	PlayerHealth = 3;
}

void AOvalRunnerGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (UGameplayStatics::DoesSaveGameExist(SaveSlot, UserIndex))
	{
		SaveScoreInstance = Cast<USaveScore>(UGameplayStatics::LoadGameFromSlot(SaveSlot, UserIndex));
	}
	else
	{
		SaveScoreInstance = Cast<USaveScore>(UGameplayStatics::CreateSaveGameObject(USaveScore::StaticClass()));
	}
}

void AOvalRunnerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentScore += DeltaTime;
}

void AOvalRunnerGameModeBase::DamagePlayer()
{

	if (PlayerHealth > 0) // Avoid looping from 0 to 255
	PlayerHealth--;

	if (PlayerHealth == 0)
	{
		if (SaveScoreInstance != nullptr)
		{
			HighScore = SaveScoreInstance->HighScore;

			if (HighScore < CurrentScore)
			{
				SaveScoreInstance->HighScore = CurrentScore;

				UGameplayStatics::SaveGameToSlot(SaveScoreInstance, SaveSlot, UserIndex);
			}
		}

		UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
	}
}
