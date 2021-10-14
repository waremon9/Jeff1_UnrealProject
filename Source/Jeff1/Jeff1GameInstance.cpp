// Fill out your copyright notice in the Description page of Project Settings.


#include "Jeff1GameInstance.h"

FName UJeff1GameInstance::GetNextLevelName()
{
	return LevelNames[(++CurrentLevel)%LevelNames.Num()];
}

void UJeff1GameInstance::Init()
{
	UGameInstance::Init();

	LevelNames.Add(FName("GameMap"));
}
