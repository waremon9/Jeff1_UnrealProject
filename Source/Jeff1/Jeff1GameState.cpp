// Fill out your copyright notice in the Description page of Project Settings.


#include "Jeff1GameState.h"

#include "Kismet/GameplayStatics.h"

AJeff1GameState::AJeff1GameState()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> FoodBlueprint(TEXT("Blueprint'/Game/Assets/BP_Food.BP_Food'"));
	if (FoodBlueprint.Object){
		FoodBP = (UClass*)FoodBlueprint.Object->GeneratedClass;
	}
}

int AJeff1GameState::GetFoodAcquired()
{
	return FoodAcquired;
}