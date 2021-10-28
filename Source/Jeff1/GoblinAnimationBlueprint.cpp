// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinAnimationBlueprint.h"

#include "AiGoblinCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UGoblinAnimationBlueprint::UGoblinAnimationBlueprint()
{
	Speed = 0;
}

void UGoblinAnimationBlueprint::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AActor* OwningActor = GetOwningActor();

	if(OwningActor && Cast<AAiGoblinCharacter>(OwningActor) && Cast<AAiGoblinCharacter>(OwningActor)->GetMoveComp())
	{
		Speed = OwningActor->GetVelocity().Size() / Cast<AAiGoblinCharacter>(OwningActor)->GetMoveComp()->MaxWalkSpeed;

		CarryFood = Cast<AAiGoblinCharacter>(OwningActor)->IsCarryingFood();
	}
}