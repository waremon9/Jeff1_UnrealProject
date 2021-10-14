// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Jeff1GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API UJeff1GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	int CurrentLevel = 0;

	UFUNCTION()
	FName GetNextLevelName();
};
