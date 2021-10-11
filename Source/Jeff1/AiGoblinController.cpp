// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinController.h"
#include "AiGoblinCharacter.h"
#include "BotBasePoint.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

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

	
	UE_LOG(LogTemp, Warning, TEXT("Goblin character possessed"));
 
	//Get the possessed Character and check if it's my own AI Character
	AAiGoblinCharacter* AIChar = Cast<AAiGoblinCharacter>(InPawn);
 
	if (AIChar)
	{
		//If the blackboard is valid initialize the blackboard for the corresponding behavior tree
		if (AIChar->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
		}
 
		/*Populate the array of available bot target points
		The following function needs a TArray of AActors, that's why I declared the
		BotTargetPoints as such. When I will need to get an exact point and compare it,
		I will cast it to the corresponding class (ABotTargetPoint)*/
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABotTargetPoint::StaticClass(), BotTargetPoints);

		//get the starting point and ending point of goblin
		BlackboardComp->SetValueAsObject("BaseLocation", UGameplayStatics::GetActorOfClass(GetWorld(), ABotBasePoint::StaticClass()));
 
		//Start the behavior tree which corresponds to the specific character
		BehaviorComp->StartTree(*AIChar->BehaviorTree);
	}
}