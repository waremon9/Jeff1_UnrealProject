// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinAnimationBlueprint.h"

#include "AiGoblinCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UGoblinAnimationBlueprint::UGoblinAnimationBlueprint()
{
	Speed = 0;
}

void UGoblinAnimationBlueprint::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	AActor* OwningActor = GetOwningActor();
	if(OwningActor)
	{
		Goblin = Cast<AAiGoblinCharacter>(OwningActor);
		if(Goblin==nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Goblin anim bp can't get owning goblin"));
		}
		else
		{
			if(Goblin->GetMoveComp())
			{
				MaxSpeed = Goblin->GetMoveComp()->GetMaxSpeed();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Goblin anim bp can't get owning goblin Mov comp"));
			}
		}
	}
}

void UGoblinAnimationBlueprint::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(Goblin)
	{
		//update variable used by anim bp
		Speed = Goblin->GetVelocity().Size() / MaxSpeed;

		CarryFood = Goblin->IsCarryingFood();
	}
}
