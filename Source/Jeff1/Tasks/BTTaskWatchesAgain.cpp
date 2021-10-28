// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskWatchesAgain.h"

#include "../AiGoblinCharacter.h"
#include "../AiGoblinController.h"

EBTNodeResult::Type UBTTaskWatchesAgain::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());

		if (Character)
		{
			Character->SetWatchingForKnight(true);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
