// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AKnight::AKnight()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;

	//camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}


// Called when the game starts or when spawned
void AKnight::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->Possess(this);
}

void AKnight::MoveForward(float value)
{
	FVector direction = this->GetActorForwardVector();
	AddMovementInput(direction, value);
}

void AKnight::MoveRight(float value)
{
	FVector direction = this->GetActorRightVector();
	AddMovementInput(direction, value);
}

void AKnight::TurnCamera(float value)
{
	FRotator rotation = FRotator(0,1,0);
	CameraBoom->SetRelativeRotation(rotation*value*TurnCameraSpeedModifier + CameraBoom->GetRelativeRotation());
}

void AKnight::LookUp(float value)
{
	FRotator rotation = FRotator(1,0,0);
	FRotator nextRotation = CameraBoom->GetRelativeRotation() + rotation*value*LookUpSpeedModifier;
	if(nextRotation.Pitch >= MinPitch && nextRotation.Pitch <= MaxPitch)
	{
		CameraBoom->SetRelativeRotation(nextRotation);
	}
}

// Called every frame
void AKnight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKnight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AKnight::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKnight::MoveRight);
	PlayerInputComponent->BindAxis("TurnCamera", this, &AKnight::TurnCamera);
	PlayerInputComponent->BindAxis("LookUp", this, &AKnight::LookUp);
}