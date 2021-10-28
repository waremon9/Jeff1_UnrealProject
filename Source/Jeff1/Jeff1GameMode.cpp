// Copyright Epic Games, Inc. All Rights Reserved.


#include "Jeff1GameMode.h"

#include "AiGoblinCharacter.h"
#include "AiGoblinController.h"
#include "Jeff1GameState.h"
#include "Jeff1GameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AJeff1GameMode::AJeff1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Assets/BP_Knight'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AJeff1GameMode::BeginPlay()
{
	Super::BeginPlay();

	Jeff1GameState = Cast<AJeff1GameState>(GameState);
	if(!Jeff1GameState)
	{
		UGameViewportClient* const Viewport = GetWorld()->GetGameViewport();
		if (Viewport)
		{
			Viewport->ConsoleCommand("quit");
		}
	}

	GameHUD = Cast<AInGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(!GameHUD)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't get hud ref in GameMode"));
	}
}

//Called once all begin play from placed actor are done to be sure AILocationManager ref has been given to the GameState
void AJeff1GameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	AJeff1GameState* GM = Cast<AJeff1GameState>(GameState);
	TArray<AActor*> Points = GM->GetAiLocationManager()->GetAllBotTarget();

	ABotTargetPoint* TargetPoint = Cast<ABotTargetPoint>(Points[FMath::RandRange(0, Points.Num() - 1)]);
	
	FActorSpawnParameters SpawnInfo;
	AFood* f = GetWorld()->SpawnActor<AFood>(
		Cast<AJeff1GameState>(GameState)->GetFoodBP(),
		TargetPoint->GetFoodLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);

	f->SetActorEnableCollision(false);
	f->StaticMesh->SetSimulatePhysics(false);
	TargetPoint->SetFoodOn(f);

	Jeff1GameState->GetGoblinManager()->SpawnNewGoblin();
}

void AJeff1GameMode::CheckForWin()
{
	if (Jeff1GameState->FoodRequired <= Jeff1GameState->FoodAcquired)
	{
		Win();
	}
}

void AJeff1GameMode::Loose()
{
	if(!GameEnded)
	{
		EndGame();
		if(GameHUD)
		{
			GameHUD->GameEnded(false);
		}
	}
}

void AJeff1GameMode::Win()
{
	if(!GameEnded)
	{
		EndGame();
		if(GameHUD)
		{
			GameHUD->GameEnded(true);
		}
	}
}


void AJeff1GameMode::EndGame()
{
	GameEnded = true;
	GetWorld()->GetFirstPlayerController()->GetCharacter()->DisableInput(GetWorld()->GetFirstPlayerController());
}