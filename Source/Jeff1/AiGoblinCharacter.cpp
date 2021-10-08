// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAiGoblinCharacter::AAiGoblinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAiGoblinCharacter::BeginPlay()
{
	Super::BeginPlay();

	Movement = Cast<UCharacterMovementComponent>(this->GetMovementComponent());
	Movement->MaxWalkSpeed = MoveSpeed;
}

// Called every frame
void AAiGoblinCharacter::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAiGoblinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

