// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AiGoblinCharacter.generated.h"

UCLASS()
class JEFF1_API AAiGoblinCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAiGoblinCharacter();
	
	UPROPERTY(EditAnywhere,Category="AI")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere)
	UCharacterMovementComponent* Movement;
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 680;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
