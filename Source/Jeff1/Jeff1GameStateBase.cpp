// Fill out your copyright notice in the Description page of Project Settings.


#include "Jeff1GameStateBase.h"

#include "BotBasePoint.h"
#include "BotTargetPoint.h"
#include "Kismet/GameplayStatics.h"

AJeff1GameStateBase::AJeff1GameStateBase()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Assets/Goblin/BP_AiGoblinCharacter.BP_AiGoblinCharacter'"));
	if (ItemBlueprint.Object){
		GoblinBP = (UClass*)ItemBlueprint.Object->GeneratedClass;
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
