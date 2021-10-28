// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskDeposeFood.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskDeposeFood::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();
	
	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());

		if (Character)
		{
			ABotTargetPoint* point = Cast<ABotTargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"));
			if(point->IsFoodOn())
			{
				return EBTNodeResult::Failed;
			}
			
			Character->DeposeFood(point);
			
			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
