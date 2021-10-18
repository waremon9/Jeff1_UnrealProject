// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AiGoblinController.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AAiGoblinController : public AAIController
{
	GENERATED_BODY()
 
	
protected:
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BTHandFree;
	UPROPERTY(EditDefaultsOnly)
	class UBehaviorTree* BTCarryFood;
	
public:
	
	/*----------Constructor----------*/
	AAiGoblinController();
	
	void SetFoodBT();
	void SetHandFreeBT();
};
