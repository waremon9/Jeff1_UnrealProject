// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Manager/AiLocationManager.h"
#include "Manager/GoblinManager.h"
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
	UPROPERTY(VisibleDefaultsOnly)
	AGoblinManager* GoblinManager;
	
	//Food blueprint
	TSubclassOf<class AFood> FoodBP;

public:
	AJeff1GameState();

	UFUNCTION()
	void SetAiLocationManager(AAiLocationManager* Ref){AiLocationManager = Ref;}
	UFUNCTION()
	void SetGoblinManager(AGoblinManager* Ref){GoblinManager = Ref;}
	UFUNCTION()
	AAiLocationManager* GetAiLocationManager(){return AiLocationManager;}
	UFUNCTION()
	AGoblinManager* GetGoblinManager(){return GoblinManager;}

	UFUNCTION()
	TSubclassOf<class AFood> GetFoodBP(){return FoodBP;}

	UFUNCTION()
	int GetFoodAcquired();

	int FoodInMap = 0;
	int MaxFoodInMap = 5;
	int FoodAcquired = 0;
	int FoodRequired = 5;
	int GoblinInMap = 0;
	int MaxGoblinOnMap = 2;
	float GoblinRespawnMaxTime = 5.f;
	
};
