// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BotTargetPoint.h"
#include "Food.h"
#include "GameFramework/Character.h"
#include "FoodCarryingCharacter.generated.h"

UCLASS()
class JEFF1_API AFoodCarryingCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	//Movement component to adjust speed
	UPROPERTY(VisibleDefaultsOnly)
	UCharacterMovementComponent* MovComp;

	//Hand socket to crry food
	UPROPERTY(VisibleDefaultsOnly)
	USkeletalMeshSocket const* Hand;

	//Food getting carried
	UPROPERTY(VisibleAnywhere)
	AFood* Food;

	//Base movespeed
	UPROPERTY(EditDefaultsOnly)
	float MoveSpeed = 900;
	
public:
	// Sets default values for this character's properties
	AFoodCarryingCharacter();

	virtual void Initialize();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CarryFood(AFood* food);
	AFood* DropFood();
	AFood* DeposeFood(ABotTargetPoint* Location);

	UCharacterMovementComponent* GetMoveComp(){return MovComp;}
	USkeletalMeshSocket const* GetHand() {return Hand;}
	float GetMoveSpeed(){return MoveSpeed;}
	bool IsCarryingFood(){return Food != nullptr;}
};
