// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AiGoblinCharacter.h"
#include "GameFramework/GameMode.h"
#include "Jeff1GameMode.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AJeff1GameMode : public AGameMode
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly)
	FTimerHandle GoblinRespawnTimer;
	UPROPERTY(VisibleDefaultsOnly)
	FTimerHandle GoblinLimitIncreaseTimer;
	
protected:
	UFUNCTION()
	void SpawnNewGoblin();
	UFUNCTION()
	void SpawnNewGoblinWithTimer();
	UFUNCTION()
	void IncreaseMaxGoblinLimit(int Increase);

	virtual void BeginPlay() override;

	virtual void HandleMatchHasStarted() override;
	
	public:
	AJeff1GameMode();

	UFUNCTION()
	void DespawnGoblin(AAiGoblinCharacter* Goblin);

	UFUNCTION()
	void CheckForWin();

	UFUNCTION()
	void SwitchLevel();
};
