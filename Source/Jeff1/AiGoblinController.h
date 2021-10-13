// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AiGoblinController.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AAiGoblinController : public AAIController
{
	GENERATED_BODY()
	
	/*Behavior tree comp ref*/
	UBehaviorTreeComponent* BehaviorComp;
   
	/*----------Blackboard----------*/
 
	/*Blackboard comp ref*/
	UBlackboardComponent* BlackboardComp;
 
	/*----------Blackboard----------*/
 
	/*Posses is executed when the character we want to control is spawned.
	Inside this function, we initialize the blackboard and start the behavior tree*/
	virtual void OnPossess(APawn* InPawn) override;
 
public:
	/*----------Constructor----------*/
	AAiGoblinController();
 
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
};
