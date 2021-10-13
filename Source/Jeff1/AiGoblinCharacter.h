// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FoodCarryingCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AiGoblinCharacter.generated.h"

UCLASS()
class JEFF1_API AAiGoblinCharacter : public AFoodCarryingCharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	class UBehaviorTree* UsedBehaviourTree;
	
public:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BTHandFree;
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BTCarryFood;

	void ChooseRightBT();
	
	UBehaviorTree* GetUsedBehavioutTree(){return UsedBehaviourTree;}
	
	// Sets default values for this character's properties
	AAiGoblinCharacter();
	
	virtual void BeginPlay() override;
};