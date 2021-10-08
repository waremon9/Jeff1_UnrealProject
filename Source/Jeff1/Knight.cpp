// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AKnight::AKnight()
{
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	
	//camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	CameraZoom_v = CameraBoom->TargetArmLength;

	//camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}


// Called when the game starts or when spawned
void AKnight::BeginPlay()
{
	Super::BeginPlay();
}

void AKnight::MoveForward(float value)
{
	if ((Controller != nullptr) && (value != 0.0f))
{
	// find out which way is forward
	const FRotator rotation = Controller->GetControlRotation();
	const FRotator yawRotation(0, rotation.Yaw, 0);

	// get forward vector
	const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(direction, value);
}
}

void AKnight::MoveRight(float value)
{
	if ( (Controller != nullptr) && (value != 0.0f) )
	{
		// find out which way is right
		const FRotator rotation = Controller->GetControlRotation();
		const FRotator yawRotation(0, rotation.Yaw, 0);
	
		// get right vector 
		const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(direction, value);
	}
}

void AKnight::CameraZoomIn()
{
	//Reduce camera boom lenght and check if not to short then apply
	if((CameraZoom_v -= ZoomSpeed) <= MinCameraLength)
		CameraZoom_v = MinCameraLength;
	
	CameraBoom->TargetArmLength = CameraZoom_v;
}

void AKnight::CameraZoomOut()
{
	//increase camera boom lenght and check if not to long then apply
	if((CameraZoom_v += ZoomSpeed) >= MaxCameraLength)
		CameraZoom_v = MaxCameraLength;
	
	CameraBoom->TargetArmLength = CameraZoom_v;
}

// Called every frame
void AKnight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKnight::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Movement input
	PlayerInputComponent->BindAxis("MoveForward", this, &AKnight::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKnight::MoveRight);

	//Camera movement input
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//camera zoom input
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &AKnight::CameraZoomIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &AKnight::CameraZoomOut);
	
}