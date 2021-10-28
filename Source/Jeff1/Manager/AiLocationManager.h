// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BotBasePoint.h"
#include "../BotTargetPoint.h"
#include "GameFramework/Actor.h"
#include "AiLocationManager.generated.h"

UCLASS()
class JEFF1_API AAiLocationManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAiLocationManager();

protected:
	UPROPERTY(EditAnywhere)
	TArray<AActor*> AllFoodBotTargetPoints;
	//because TArray<ABotTargetPoint*> decided to not work
	UPROPERTY(EditAnywhere)
	ABotBasePoint* BaseLocation;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	TArray<AActor*> GetAllBotTarget(){return AllFoodBotTargetPoints;}
	ABotBasePoint* GetBaseLocation(){return BaseLocation;}
};
