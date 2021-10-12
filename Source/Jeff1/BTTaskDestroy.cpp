// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskDestroy.h"

#include "AiGoblinController.h"
#include "GameFramework/Character.h"

EBTNodeResult::Type UBTTaskDestroy::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
 
	if (AICon)
	{
		AICon->GetCharacter()->Destroy();
		
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
