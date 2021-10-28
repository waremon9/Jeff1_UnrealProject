// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodCarryingCharacter.h"

#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFoodCarryingCharacter::AFoodCarryingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AFoodCarryingCharacter::Initialize()
{
	MovComp = Cast<UCharacterMovementComponent>(ACharacter::GetMovementComponent());
	if(MovComp)
	{
		MovComp->MaxWalkSpeed = MoveSpeed;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FoodCarryingCharacter can't get MovementComponent ref"));
	}
	
	Hand = this->GetMesh()->GetSocketByName("Right_Hand");
	if(Hand==nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("FoodCarryingCharacter can't get hand socket ref"));
	}
}

// Called when the game starts or when spawned
void AFoodCarryingCharacter::BeginPlay()
{
	Super::BeginPlay();

	Initialize();
}

// Called every frame
void AFoodCarryingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodCarryingCharacter::CarryFood(AFood* food)
{
	Food = food; //give food to character
	Food->StaticMesh->SetSimulatePhysics(false); //stop physic of carried food
	Food->SetActorEnableCollision(false);
	
	if(Hand && MovComp)
	{
		Hand->AttachActor(Food, this->GetMesh()); //add food to hand socket
		MovComp->MaxWalkSpeed = MoveSpeed/2.f; //reduce character speed
	}
}

AFood* AFoodCarryingCharacter::DropFood()
{
	Food->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform); //Detach food from hand
	Food->StaticMesh->SetSimulatePhysics(true); //give physic back to carried food
	Food->SetActorEnableCollision(true);
	AFood* TheItemToReturn = Food;
	Food = nullptr;
	MovComp->MaxWalkSpeed = MoveSpeed; //reset character speed

	return TheItemToReturn;
}

AFood* AFoodCarryingCharacter::DeposeFood(ABotTargetPoint* Location)
{
	if(Food)
	{
		Food->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform); //Detach food from hand
		Food->SetActorLocation(Location->GetFoodLocation());
		Location->SetFoodOn(Food);
		AFood* TheItemToReturn = Food;
		Food = nullptr;
		MovComp->MaxWalkSpeed = MoveSpeed; //reset character speed

		return TheItemToReturn;
	}
	
	return Food;
}