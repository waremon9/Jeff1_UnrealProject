// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KnightAnimationBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API UKnightAnimationBlueprint : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UKnightAnimationBlueprint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CarryFood;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
