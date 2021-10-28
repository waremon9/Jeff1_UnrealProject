// Fill out your copyright notice in the Description page of Project Settings.


#include "Jeff1GameState.h"

#include "Kismet/GameplayStatics.h"

AJeff1GameState::AJeff1GameState()
{
}

int AJeff1GameState::GetFoodAcquired()
{
	return FoodAcquired;
}

int AJeff1GameState::GetFoodRequired()
{
	return FoodRequired;
}
