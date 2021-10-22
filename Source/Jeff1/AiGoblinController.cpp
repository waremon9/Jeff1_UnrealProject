// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinController.h"

#include "AiGoblinCharacter.h"
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

void AAiGoblinController::OnDetectKnight(FVector KnightLocation)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "A Goblin saw the Knight ! (\"ondetect\"");
	
	GetPawn<AAiGoblinCharacter>()->SetWatchForKnight(false);
	
	Blackboard->SetValueAsObject("BaseLocation", GetWorld()->GetGameState<AJeff1GameState>()->GetAiLocationManager()->GetBaseLocation());
	Blackboard->SetValueAsVector("KnightLocation", KnightLocation);
	
	RunBehaviorTree(BTPursuit);
}
