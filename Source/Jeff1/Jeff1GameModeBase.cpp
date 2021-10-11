// Copyright Epic Games, Inc. All Rights Reserved.


#include "Jeff1GameModeBase.h"

#include "AiGoblinCharacter.h"
#include "BotBasePoint.h"
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

	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Assets/Goblin/BP_AiGoblinCharacter.BP_AiGoblinCharacter'"));
	if (ItemBlueprint.Object){
		GoblinBP = (UClass*)ItemBlueprint.Object->GeneratedClass;
	}
}

void AJeff1GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	BaseLocation = UGameplayStatics::GetActorOfClass(GetWorld(), ABotBasePoint::StaticClass());

	//2 goblin appear at the start
	SpawnNewGoblin();
	SpawnNewGoblin();
}

void AJeff1GameModeBase::SpawnNewGoblin()
{
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AAiGoblinCharacter>(GoblinBP,
		BaseLocation->GetActorLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);
}
