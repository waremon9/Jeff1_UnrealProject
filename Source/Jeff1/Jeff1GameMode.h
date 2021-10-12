// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Jeff1GameMode.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AJeff1GameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:
	UFUNCTION()
	void SpawnNewGoblin();

	virtual void BeginPlay() override;

	virtual void HandleMatchHasStarted() override;
	
	public:
	AJeff1GameMode();
};
