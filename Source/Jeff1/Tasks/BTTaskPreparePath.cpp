// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskPreparePath.h"

#include "../AiGoblinCharacter.h"
#include "../AiGoblinController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskPreparePath::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
	
	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		if (Character && BlackboardComp)
		{
			FVector KnightDirection = BlackboardComp->GetValueAsVector("KnightDirection");
			KnightDirection.Normalize();
			Character->SetMovingTowards(KnightDirection);

			//Calling AAiGoblinCharacter::MoveTowards without looping
			Character->GetWorldTimerManager().SetTimer(TimerHandle, Character, &AAiGoblinCharacter::StopMovingTowards, 3.f, false);
			
			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
