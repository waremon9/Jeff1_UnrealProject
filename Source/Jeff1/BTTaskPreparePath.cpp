// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskPreparePath.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"
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
			const FVector location  = Character->GetActorLocation();
			const FVector direction = BlackboardComp->GetValueAsVector("KnightDirection");
			const float speed = Character->GetMoveSpeed();
			
			BlackboardComp->SetValueAsVector("KnightLocation", (location + (direction * speed * 3000.0f)));
			
			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
