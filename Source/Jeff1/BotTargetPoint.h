// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "GameFramework/Actor.h"
#include "BotTargetPoint.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API ABotTargetPoint : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	USceneComponent* RootScene;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* FoodLocation;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleDefaultsOnly)
	AFood* Food;

public:
	ABotTargetPoint();

	FVector GetFoodLocation();
	void SetFoodOn(AFood* f){Food = f;}
	void RemoveFoodOn(){Food = nullptr;}
	bool IsFoodOn(){return Food!=nullptr;}
	AFood* getFoodOn(){return Food;}
};
