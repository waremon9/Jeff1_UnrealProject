
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AiGoblinCharacter.h"
#include "GoblinAnimationBlueprint.generated.h"

/**
* 
*/
UCLASS()
class JEFF1_API UGoblinAnimationBlueprint : public UAnimInstance
{
	GENERATED_BODY()

	UPROPERTY()
	AAiGoblinCharacter* Goblin;

	UPROPERTY()
	float MaxSpeed;
	
	public:
	UGoblinAnimationBlueprint();

	virtual void NativeBeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CarryFood;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
