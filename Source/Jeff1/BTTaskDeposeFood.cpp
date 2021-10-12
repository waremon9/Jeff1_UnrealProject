// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskDeposeFood.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskDeposeFood::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
	
	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());

		if (Character)
		{
			AFood* Food = Character->DropFood();
			Food->SetActorLocation(Cast<ABotTargetPoint>(BlackboardComp->GetValueAsObject("LocationToGo"))->GetActorLocation());
			
			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
