// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskDropFood.h"

#include "../AiGoblinCharacter.h"
#include "../AiGoblinController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTaskDropFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		if (Character && BlackboardComp)
		{
			if(Character->IsCarryingFood())
				BlackboardComp->SetValueAsVector("FoodLocation", Character->DropFood()->GetActorLocation());

			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
