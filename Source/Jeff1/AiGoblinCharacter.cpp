// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAiGoblinCharacter::AAiGoblinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 680;
}