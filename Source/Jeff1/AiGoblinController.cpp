// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinController.h"
#include "AiGoblinCharacter.h"
#include "Jeff1GameStateBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

class AJeff1GameStateBase;

AAiGoblinController::AAiGoblinController()
{
	//Initialize BehaviorTreeComponent, BlackboardComponent and the corresponding key
 
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
 
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
 
	LocationToGoKey = "LocationToGo";
 
}
 
void AAiGoblinController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
 
	//Get the possessed Character and check if it's my own AI Character
	AAiGoblinCharacter* AIChar = Cast<AAiGoblinCharacter>(InPawn);
 
	if (AIChar)
	{
		//If the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (AIChar->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
		}
 
		//Get all food location
		BotTargetPoints = GetWorld()->GetGameState<AJeff1GameStateBase>()->GetBotTargetPoints();

		//get the starting point and ending point of goblin
		BlackboardComp->SetValueAsObject("BaseLocation", GetWorld()->GetGameState<AJeff1GameStateBase>()->GetBaseLocation());
 
		//Start the behavior tree which corresponds to the specific character
		BehaviorComp->StartTree(*AIChar->BehaviorTree);
	}
}