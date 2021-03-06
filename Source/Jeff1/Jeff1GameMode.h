// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AiGoblinCharacter.h"
#include "Jeff1GameState.h"
#include "GameFramework/GameMode.h"
#include "Jeff1GameMode.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AJeff1GameMode : public AGameMode
{
	GENERATED_BODY()

	UPROPERTY()
	AJeff1GameState* Jeff1GameState;
	UPROPERTY()
	AInGameHUD* GameHUD;
	
protected:
	virtual void BeginPlay() override;

	virtual void HandleMatchHasStarted() override;

	UPROPERTY()
	bool GameEnded = false;

	UFUNCTION()
	void EndGame();
	
public:
	AJeff1GameMode();

	UFUNCTION()
	void CheckForWin();

	UFUNCTION()
	void Loose();
	UFUNCTION()
	void Win();
};
