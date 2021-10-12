// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Jeff1GameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AJeff1GameStateBase : public AGameStateBase
{
	GENERATED_BODY()

protected:
	//all food possible location
	TArray<AActor*> BotTargetPoints;
	//entry of storage location
	AActor* BaseLocation;
	
	//Goblin blueprint
	TSubclassOf<class AAiGoblinCharacter> GoblinBP;
	//Food blueprint
	TSubclassOf<class AFood> FoodBP;

public:
	AJeff1GameStateBase();

	void BeginPlay() override;

	UFUNCTION()
	TArray<AActor*> GetBotTargetPoints();
	UFUNCTION()
	AActor* GetBaseLocation();
	UFUNCTION()
	TSubclassOf<class AAiGoblinCharacter> GetGoblinBP(){return GoblinBP;}
	UFUNCTION()
	TSubclassOf<class AFood> GetFoodBP(){return FoodBP;}

	int FoodInMap = 0;
	int FoodAcquired = 0;
	int GoblinInMap = 0;
};
