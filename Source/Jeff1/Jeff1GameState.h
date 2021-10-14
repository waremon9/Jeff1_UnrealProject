// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AiLocationManager.h"
#include "GameFramework/GameState.h"
#include "Jeff1GameState.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AJeff1GameState : public AGameState
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly)
	AAiLocationManager* AiLocationManager;
	
	//Goblin blueprint
	TSubclassOf<class AAiGoblinCharacter> GoblinBP;
	//Food blueprint
	TSubclassOf<class AFood> FoodBP;

public:
	AJeff1GameState();

	UFUNCTION()
	void SetAiLocationManager(AAiLocationManager* Ref){AiLocationManager = Ref;}
	UFUNCTION()
	AAiLocationManager* GetAiLocationManager(){return AiLocationManager;}

	UFUNCTION()
	TSubclassOf<class AAiGoblinCharacter> GetGoblinBP(){return GoblinBP;}
	UFUNCTION()
	TSubclassOf<class AFood> GetFoodBP(){return FoodBP;}

	int FoodInMap = 0;
	int FoodAcquired = 0;
	int GoblinInMap = 0;
	int MaxGoblinOnMap = 2;
	float GoblinRespawnMaxTime = 5.f;
};
