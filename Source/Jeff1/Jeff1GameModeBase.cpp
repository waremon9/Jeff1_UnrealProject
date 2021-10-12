// Copyright Epic Games, Inc. All Rights Reserved.


#include "Jeff1GameModeBase.h"

#include "AiGoblinCharacter.h"
#include "Jeff1GameStateBase.h"
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

	//2 goblin appear at the start
	SpawnNewGoblin();
	SpawnNewGoblin();
	
}

void AJeff1GameModeBase::SpawnNewGoblin()
{
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AAiGoblinCharacter>(
		GetWorld()->GetGameState<AJeff1GameStateBase>()->GetGoblinBP(),
		GetWorld()->GetGameState<AJeff1GameStateBase>()->GetBaseLocation()->GetActorLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);

	GetWorld()->GetGameState<AJeff1GameStateBase>()->GoblinInMap++;
}
