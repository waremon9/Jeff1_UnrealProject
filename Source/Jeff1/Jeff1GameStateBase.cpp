// Fill out your copyright notice in the Description page of Project Settings.


#include "Jeff1GameStateBase.h"

#include "BotBasePoint.h"
#include "BotTargetPoint.h"
#include "Kismet/GameplayStatics.h"

AJeff1GameStateBase::AJeff1GameStateBase()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> GoblinBlueprint(TEXT("Blueprint'/Game/Assets/Goblin/BP_AiGoblinCharacter.BP_AiGoblinCharacter'"));
	if (GoblinBlueprint.Object){
		GoblinBP = (UClass*)GoblinBlueprint.Object->GeneratedClass;
	}
	static ConstructorHelpers::FObjectFinder<UBlueprint> FoodBlueprint(TEXT("Blueprint'/Game/Assets/BP_Food.BP_Food'"));
	if (FoodBlueprint.Object){
		FoodBP = (UClass*)FoodBlueprint.Object->GeneratedClass;
	}
}

void AJeff1GameStateBase::BeginPlay()
{
	Super::BeginPlay();
}

TArray<AActor*> AJeff1GameStateBase::GetBotTargetPoints()
{
	if(BotTargetPoints.Num()==0)UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABotTargetPoint::StaticClass(), BotTargetPoints);
	return BotTargetPoints;
}

AActor* AJeff1GameStateBase::GetBaseLocation()
{
	if(!BaseLocation) BaseLocation = UGameplayStatics::GetActorOfClass(GetWorld(), ABotBasePoint::StaticClass());
	return  BaseLocation;
}
