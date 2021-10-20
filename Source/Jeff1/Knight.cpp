// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight.h"

#include "Chest.h"
#include "Food.h"
#include "AiGoblinCharacter.h"
#include "Jeff1GameState.h"
#include "Camera/CameraComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Jeff1GameMode.h"

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

	//Box for interacting with food
	BoxInteract = CreateDefaultSubobject<UBoxComponent>("BoxInteract");
	BoxInteract->SetupAttachment(RootComponent);
}

void AKnight::BeginPlay()
{
	AFoodCarryingCharacter::BeginPlay();

	GetMesh()->OnComponentHit.AddDynamic(this, &AKnight::OnComponentHit);
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

void AKnight::Interact()
{
	if(Food) InteractFoodInHand();
	else InteractNoFoodInHand();
}

void AKnight::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((AAiGoblinCharacter*) OtherActor->StaticClass() != nullptr)
		GetWorld()->GetAuthGameMode<AJeff1GameMode>()->Loose();
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

void AKnight::InteractNoFoodInHand()
{
	//get all food in front of knight
	TArray<AActor*> Actors;
	BoxInteract->GetOverlappingActors(Actors);

	for(AActor* food : Actors)//for all overlapping actor
	{
		if(Cast<AFood>(food))//if actor is AFood
		{
			if(Hand)//Hand socket isn't null
			{
				CarryFood(Cast<AFood>(food));
			} else UE_LOG(LogTemp, Error, TEXT("Hand socket nullptr"));
			return;
		}
	}
}

void AKnight::InteractFoodInHand()
{
	//Is chest in front of knight?
	TArray<AActor*> Actors;
	BoxInteract->GetOverlappingActors(Actors);

	for(AActor* a : Actors)//for all overlapping actor
	{
		if(Cast<AChest>(a))//if actor is AChest
		{
			MovComp->MaxWalkSpeed = MoveSpeed; //reset player speed
			Food->Destroy(); //Food in chest so destroy
			Food = nullptr; //clear pointer
			
			GetWorld()->GetGameState<AJeff1GameState>()->FoodAcquired++;
			GetWorld()->GetGameState<AJeff1GameState>()->FoodInMap--;
			
			GetWorld()->GetAuthGameMode<AJeff1GameMode>()->CheckForWin();

			return;
		}
		
		if(Cast<ABotTargetPoint>(a))//if actor is food location
			{
				DeposeFood(a->GetActorLocation());

				return;
			}
		}

	//no chest to interact with, drop food on the floor
	DropFood();
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

	//InteractInput
	PlayerInputComponent->BindAction("Interact",IE_Pressed, this, &AKnight::Interact);
	
}