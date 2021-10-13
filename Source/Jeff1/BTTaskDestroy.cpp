// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskDestroy.h"

#include "AiGoblinController.h"
#include "Jeff1GameMode.h"

EBTNodeResult::Type UBTTaskDestroy::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
 
	if (AICon)
	{
		GetWorld()->GetAuthGameMode<AJeff1GameMode>()->DespawnGoblin(Cast<AAiGoblinCharacter>(AICon->GetCharacter()));
		
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
