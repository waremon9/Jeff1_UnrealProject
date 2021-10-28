// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveTowards.h"

#include "../AiGoblinCharacter.h"
#include "../AiGoblinController.h"

EBTNodeResult::Type UBTTask_MoveTowards::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
	
	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		if (Character && BlackboardComp)
		{

			
			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
	
	return UBTTask_MoveTo::ExecuteTask(OwnerComp, NodeMemory);
}
