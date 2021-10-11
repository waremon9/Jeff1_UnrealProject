// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskDestroy.h"

#include "AiGoblinController.h"
#include "GameFramework/Character.h"

EBTNodeResult::Type UBTTaskDestroy::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
 
	/*If the Controller is valid:
	1)Get the Blackboard Component and the Current Point of the bot
	2)Search for the next point, which will be different from the Current Point*/
	if (AICon)
	{
		AICon->GetCharacter()->Destroy();
		
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
