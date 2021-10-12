// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "FoodCarryingCharacter.h"
#include "GameFramework/Character.h"
#include "AiGoblinCharacter.generated.h"

UCLASS()
class JEFF1_API AAiGoblinCharacter : public AFoodCarryingCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAiGoblinCharacter();
	
	UPROPERTY(EditAnywhere,Category="AI")
	class UBehaviorTree* BehaviorTree;
};