// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Jeff1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AJeff1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AActor* BaseLocation; //TODO : move to gamestate
	
	TSubclassOf<class AAiGoblinCharacter> GoblinBP;
	
protected:
	UFUNCTION()
	void SpawnNewGoblin();
	
	public:
	AJeff1GameModeBase();

	virtual void BeginPlay() override;
};
