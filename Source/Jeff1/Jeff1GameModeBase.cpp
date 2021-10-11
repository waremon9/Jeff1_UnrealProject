// Copyright Epic Games, Inc. All Rights Reserved.


#include "Jeff1GameModeBase.h"

#include "AiGoblinCharacter.h"
#include "Jeff1GameStateBase.h"
#include "Knight.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"


AJeff1GameModeBase::AJeff1GameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Assets/BP_Knight'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AJeff1GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	BaseLocation = GetWorld()->GetGameState<AJeff1GameStateBase>()->GetBaseLocation();
	GoblinBP = GetWorld()->GetGameState<AJeff1GameStateBase>()->GetGoblinBP();

	//2 goblin appear at the start
	SpawnNewGoblin();
	SpawnNewGoblin();
	
}

void AJeff1GameModeBase::SpawnNewGoblin()
{
	FActorSpawnParameters SpawnInfo;
	AAiGoblinCharacter* Goblin = GetWorld()->SpawnActor<AAiGoblinCharacter>(GoblinBP,
		BaseLocation->GetActorLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);

	GetWorld()->GetGameState<AJeff1GameStateBase>()->GoblinArray.Push(Goblin);
}
