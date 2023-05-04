// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveScore.generated.h"

/**
 * 
 */
UCLASS()
class OVALRUNNER_API USaveScore : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  Category = Basic)
	float HighScore;
	
};
