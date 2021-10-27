// Fill out your copyright notice in the Description page of Project Settings.


#include "BotTargetPoint.h"

ABotTargetPoint::ABotTargetPoint()
{
	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	RootComponent = RootScene;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootScene);

	FoodLocation = CreateDefaultSubobject<USceneComponent>("FoodLocation");
	FoodLocation->SetupAttachment(RootScene);
}

FVector ABotTargetPoint::GetFoodLocation()
{
	return FoodLocation->GetComponentLocation();
}
