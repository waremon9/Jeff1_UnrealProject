// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinCharacter.h"

#include <string>

#include "AiGoblinController.h"

// Sets default values
AAiGoblinCharacter::AAiGoblinCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;
}

void AAiGoblinCharacter::BeginPlay()
{
	Super::BeginPlay();

	Knight = GetWorld()->GetFirstPlayerController()->GetPawn<AKnight>();
	bIsMovingTowards = false;
}

void AAiGoblinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(!Knight)
	{
		GEngine->AddOnScreenDebugMessage(-1, 12.0f, FColor::Red, TEXT("Le Knight est un nullptr ?!?"));
		return;
	}

	if(bIsMovingTowards)
		AddMovementInput(KnightDirection, DeltaTime);
	
	if(!WatchesForKnight)
		return;
	
	FVector VGobToKnight = Knight->GetActorLocation()-GetActorLocation();

	//Distance check
	if(VGobToKnight.Size() > DistanceSight)
		return;

	//Side sight check
	if(FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(VGobToKnight, GetActorForwardVector()))) > SideSight / 2)
		return;

	//Obstacle check
	FCollisionQueryParams TraceParams(TEXT("TraceActor"), true, this);

	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = false;

	FHitResult Hit(ForceInit);

	if(GetWorld()->LineTraceSingleByChannel(Hit,
											GetActorLocation(),
											Knight->GetActorLocation(),
											ECC_Visibility,
											TraceParams))
		return;
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "There's no obstacle");
	
	//The knight is in sight
	GetController<AAiGoblinController>()->OnDetectKnight(Knight->GetActorLocation());
}

float AAiGoblinCharacter::GetDistanceSight() const
{
	return  DistanceSight;
}

float AAiGoblinCharacter::GetSideSight() const
{
	return SideSight;
}

AKnight* AAiGoblinCharacter::GetTarget() const
{
	return Knight;
}

void AAiGoblinCharacter::SetWatchForKnight(bool _value)
{
	WatchesForKnight = _value;
}

void AAiGoblinCharacter::StopMovingTowards()
{
	bIsMovingTowards = false;
}

void AAiGoblinCharacter::SetMovingTowards(const FVector& _KnightDirection)
{
	bIsMovingTowards = true;
	KnightDirection = _KnightDirection;
}
