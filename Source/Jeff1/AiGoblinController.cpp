// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinController.h"
#include "Jeff1GameState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

AAiGoblinController::AAiGoblinController()
{
}

void AAiGoblinController::SetFoodBT()
{
	RunBehaviorTree(BTCarryFood);
	Blackboard->SetValueAsObject("BaseLocation", GetWorld()->GetGameState<AJeff1GameState>()->GetAiLocationManager()->GetBaseLocation());
}

void AAiGoblinController::SetHandFreeBT()
{
	RunBehaviorTree(BTHandFree);
	Blackboard->SetValueAsObject("BaseLocation", GetWorld()->GetGameState<AJeff1GameState>()->GetAiLocationManager()->GetBaseLocation());
}