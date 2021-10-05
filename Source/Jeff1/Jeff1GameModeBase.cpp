// Copyright Epic Games, Inc. All Rights Reserved.


#include "Jeff1GameModeBase.h"

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
}
