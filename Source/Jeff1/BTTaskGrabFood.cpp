// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskGrabFood.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"

EBTNodeResult::Type UBTTaskGrabFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());

	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());

		if (Character)
		{
			TArray<AActor*> OverlappingActors;
			Character->GetOverlappingActors(OverlappingActors);

			for(AActor* food : OverlappingActors)//for all overlapping actor
			{
				if(Cast<AFood>(food))//if actor is AFood
				{
					Character->CarryFood(Cast<AFood>(food));
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}
	
	return EBTNodeResult::Failed;
}
