// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskSetPursuitMode.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UBTTaskSetPursuitMode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComponent();

		if (Character && BlackboardComp)
		{
		    GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, TEXT("Pursuit mode on"));
			BlackboardComp->SetValueAsVector("KnightDirection", Character->GetTarget()->GetActorForwardVector());
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
