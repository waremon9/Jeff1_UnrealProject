// Fill out your copyright notice in the Description page of Project Settings.


#include "AiGoblinCharacter.h"

#include <string>

#include "AiGoblinController.h"

// Sets default values
AAiGoblinCharacter::AAiGoblinCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AAiGoblinCharacter::BeginPlay()
{
	Super::BeginPlay();

	Knight = GetWorld()->GetFirstPlayerController()->GetPawn<AKnight>();
}

void AAiGoblinCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if(!Knight)
	{
		GEngine->AddOnScreenDebugMessage(-1, 12.0f, FColor::Red, TEXT("Le Knight est un nullptr ?!?"));
		return;
	}

	if(!WatchesForKnight)
		return;
	
	FVector VGobToKnight = Knight->GetActorLocation()-GetActorLocation();

	//Distance check
	if(VGobToKnight.Size() > DistanceSight)
		return;

	if(false)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "The Knight is within the distance");

	//Side sight check
	if(FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(VGobToKnight, GetActorForwardVector()))) > SideSight / 2)
		return;
	
	if(false)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "The Knight is in the correct direction");

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
