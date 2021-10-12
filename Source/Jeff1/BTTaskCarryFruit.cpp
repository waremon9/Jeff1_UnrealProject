// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskCarryFruit.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"
#include "Jeff1GameStateBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine/SkeletalMeshSocket.h"

EBTNodeResult::Type UBTTaskCarryFruit::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAiGoblinController* AICon = Cast<AAiGoblinController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
	
	if (AICon)
	{
		AAiGoblinCharacter* Character =  Cast<AAiGoblinCharacter>(AICon->GetCharacter());

		if (Character)
		{
			TSubclassOf<AFood> FoodBp = GetWorld()->GetGameState<AJeff1GameStateBase>()->GetFoodBP();
			FActorSpawnParameters SpawnInfo;
			AFood* Food = GetWorld()->SpawnActor<AFood>(FoodBp, FVector::ZeroVector, FRotator::ZeroRotator, SpawnInfo);
			
			Character->CarryFood(Food); //give food and set proper physic and collision

			BlackboardComp->SetValueAsObject("Food", Food); //add food to blackboard
			
			GetWorld()->GetGameState<AJeff1GameStateBase>()->FoodInMap++;
			
			//At this point, the task has been successfully completed
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
