// Fill out your copyright notice in the Description page of Project Settings.


#include "KnightAnimationBlueprint.h"

#include "Knight.h"
#include "GameFramework/CharacterMovementComponent.h"


UKnightAnimationBlueprint::UKnightAnimationBlueprint()
{
	Speed = 0;
}

void UKnightAnimationBlueprint::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AActor* OwningActor = GetOwningActor();

	if(OwningActor && Cast<AKnight>(OwningActor) && Cast<AKnight>(OwningActor)->GetMoveComp())
	{
		Speed = OwningActor->GetVelocity().Size() / Cast<AKnight>(OwningActor)->GetMoveComp()->MaxWalkSpeed;

		CarryFood = Cast<AKnight>(OwningActor)->IsCarryingFood();
	}
}
