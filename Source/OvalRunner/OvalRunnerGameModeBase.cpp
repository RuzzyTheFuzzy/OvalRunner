// Copyright Epic Games, Inc. All Rights Reserved.


#include "OvalRunnerGameModeBase.h"

#include "Kismet/GameplayStatics.h"

AOvalRunnerGameModeBase::AOvalRunnerGameModeBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
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

void AOvalRunnerGameModeBase::FinishGame()
{
	if (SaveScoreInstance != nullptr)
	{
		HighScore = SaveScoreInstance->HighScore;

		if (HighScore < CurrentScore)
		{
			SaveScoreInstance->HighScore = CurrentScore;

			UGameplayStatics::SaveGameToSlot(SaveScoreInstance, SaveSlot, UserIndex);
		}
	} else
	{
		UE_LOG(LogTemp, Warning, TEXT("SaveScoreInstance is a null pointer. Score will not be saved"))
	}

	UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
}
