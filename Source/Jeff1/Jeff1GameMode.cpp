// Copyright Epic Games, Inc. All Rights Reserved.


#include "Jeff1GameMode.h"

#include "AiGoblinCharacter.h"
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

	//2 goblin appear at the start
	SpawnNewGoblin();
	SpawnNewGoblin();
	
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("IncreaseMaxGoblinLimit"), 1);
	
	GetWorldTimerManager().SetTimer(
		GoblinLimitIncreaseTimer,
		TimerDel,
		10.f,
		false);
}

//Called once all begin play from placed actor are done to be sure AILocationManager ref has been given to the GameState
void AJeff1GameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	AJeff1GameState* GM = Cast<AJeff1GameState>(GameState);
	TArray<ABotTargetPoint*> Points = GM->GetAiLocationManager()->GetAllBotTarget();

	FVector SpawnLocation = Points[FMath::RandRange(0, Points.Num() - 1)]->GetActorLocation();
	
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AFood>(
		Cast<AJeff1GameState>(GameState)->GetFoodBP(),
		SpawnLocation,
		FRotator::ZeroRotator,
		SpawnInfo);
}

void AJeff1GameMode::SpawnNewGoblin()
{
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AAiGoblinCharacter>(
		GetWorld()->GetGameState<AJeff1GameState>()->GetGoblinBP(),
		GetWorld()->GetGameState<AJeff1GameState>()->GetAiLocationManager()->GetBaseLocation()->GetActorLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);

	if(++Cast<AJeff1GameState>(GameState)->GoblinInMap < Cast<AJeff1GameState>(GameState)->MaxGoblinOnMap)
		SpawnNewGoblinWithTimer();
	else
		GetWorldTimerManager().ClearTimer(GoblinRespawnTimer);
}

void AJeff1GameMode::SpawnNewGoblinWithTimer()
{
	GetWorldTimerManager().SetTimer(
		GoblinRespawnTimer,
		this,
		&AJeff1GameMode::SpawnNewGoblin,
		FMath::FRandRange(0,Cast<AJeff1GameState>(GameState)->GoblinRespawnMaxTime),
		false);
}


void AJeff1GameMode::DespawnGoblin(AAiGoblinCharacter* Goblin)
{
	Goblin->Destroy();
	if(--Cast<AJeff1GameState>(GameState)->GoblinInMap==Cast<AJeff1GameState>(GameState)->MaxGoblinOnMap)
		SpawnNewGoblin();
	else
		SpawnNewGoblinWithTimer();
}

void AJeff1GameMode::IncreaseMaxGoblinLimit(int Increase)
{
	UE_LOG(LogTemp,Display,TEXT("TIMER"));
	if(Increase>0)
	{
		Cast<AJeff1GameState>(GameState)->MaxGoblinOnMap+=Increase;
		SpawnNewGoblin();
	}
	
}void AJeff1GameMode::CheckForWin()
{
	if (Cast<AJeff1GameState>(GameState)->FoodRequired <= Cast<AJeff1GameState>(GameState)->FoodAcquired)
	{
		GEngine->AddOnScreenDebugMessage(-1, 12.f, FColor::White, TEXT("C'est une win !!!"));
		SwitchLevel();
	}
}

void AJeff1GameMode::SwitchLevel()
{
	UGameplayStatics::OpenLevel(this, GetGameInstance<UJeff1GameInstance>()->GetNextLevelName(), true);
}
