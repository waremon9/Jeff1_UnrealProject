// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskTargetPointSelection.h"
#include "BotTargetPoint.h"
#include "AIGoblinController.h"
#include "Jeff1GameState.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskTargetPointSelection::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
 
	/*If the Controller is valid:
	1)Get the Blackboard Component and the Current Point of the bot
	2)Search for the next point, which will be different from the Current Point*/
	if (AICon)
	{
       
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();
		ABotTargetPoint* CurrentPoint = Cast<ABotTargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));
 
		TArray<AActor*> AvailableTargetPoints = GetWorld()->GetGameState<AJeff1GameState>()->GetAiLocationManager()->GetAllBotTarget();

		//Here, we store the possible next target point
		ABotTargetPoint* NextTargetPoint;
 
		//Find a next point which is different from the current one
		do
		{
			const int32 RandomIndex = FMath::RandRange(0, AvailableTargetPoints.Num() - 1);
			//Remember that the Array provided by the Controller function contains AActor* objects so we need to cast.
			NextTargetPoint = Cast<ABotTargetPoint>(AvailableTargetPoints[RandomIndex]);
			if(!NextTargetPoint)
			{
				UE_LOG(LogTemp, Error, TEXT("Bad cast in TaskTargetPoint"));
				return EBTNodeResult::Failed;
			}
		} while (CurrentPoint == NextTargetPoint);
 
		//Update the next location in the Blackboard so the bot can move to the next Blackboard value
		BlackboardComp->SetValueAsObject("LocationToGo", NextTargetPoint);
		
		//At this point, the task has been successfully completed
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}