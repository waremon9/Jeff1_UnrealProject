// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinCharacter.h"

#include "Jeff1GameState.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAiGoblinCharacter::AAiGoblinCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 680;
}

void AAiGoblinCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(UsedBehaviourTree == BTCarryFood)
	{
		Hand->AttachActor(Food, this->GetMesh()); //add food to hand socket
		MovComp->MaxWalkSpeed = MoveSpeed/2.f; //reduce character speed
	}
}


void AAiGoblinCharacter::ChooseRightBT()
{
	//Set the right behaviour tree
	if(GetWorld()->GetGameState<AJeff1GameState>()->FoodInMap<5)
	{
		UsedBehaviourTree = BTCarryFood;
		
		TSubclassOf<AFood> FoodBp = GetWorld()->GetGameState<AJeff1GameState>()->GetFoodBP();
		FActorSpawnParameters SpawnInfo;
		AFood* CreatedFood = GetWorld()->SpawnActor<AFood>(FoodBp, FVector::ZeroVector, FRotator::ZeroRotator, SpawnInfo);

		CarryFood(CreatedFood);

		GetWorld()->GetGameState<AJeff1GameState>()->FoodInMap++;
	}
	else
	{
		UsedBehaviourTree = BTHandFree;
	}
}
