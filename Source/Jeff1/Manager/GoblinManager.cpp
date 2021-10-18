// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinManager.h"

#include "../AiGoblinController.h"
#include "../AiGoblinCharacter.h"
#include "Jeff1/Jeff1GameState.h"

// Sets default values
AGoblinManager::AGoblinManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> GoblinBlueprint(TEXT("Blueprint'/Game/Assets/Goblin/BP_AiGoblinCharacter.BP_AiGoblinCharacter'"));
	if (GoblinBlueprint.Object){
		GoblinBP = (UClass*)GoblinBlueprint.Object->GeneratedClass;
	}
}

void AGoblinManager::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetGameState<AJeff1GameState>()->SetGoblinManager(this);
	
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("IncreaseMaxGoblinLimit"), 1);

	GetWorldTimerManager().SetTimer(
		GoblinLimitIncreaseTimer,
		TimerDel,
		10.f,
		false);
}

void AGoblinManager::SpawnNewGoblin()
{
	AJeff1GameState* Jeff1GameState = GetWorld()->GetGameState<AJeff1GameState>();

	FActorSpawnParameters SpawnInfo;
	AAiGoblinCharacter* Goblin = GetWorld()->SpawnActor<AAiGoblinCharacter>(
		GoblinBP,
		Jeff1GameState->GetAiLocationManager()->GetBaseLocation()->GetActorLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);

	AAiGoblinController* GoblinController = Cast<AAiGoblinController>(Goblin->Controller);
	if(Jeff1GameState->FoodInMap < Jeff1GameState->MaxFoodInMap)
	{
		GoblinController->SetFoodBT();
		
		TSubclassOf<AFood> FoodBp = Jeff1GameState->GetFoodBP();
		AFood* CreatedFood = GetWorld()->SpawnActor<AFood>(FoodBp, FVector::ZeroVector, FRotator::ZeroRotator, SpawnInfo);
		
		Goblin->CarryFood(CreatedFood);
		Jeff1GameState->FoodInMap++;
	}
	else
	{
		GoblinController->SetHandFreeBT();
	}

	Jeff1GameState->GoblinInMap++;

	if(Jeff1GameState->GoblinInMap < Jeff1GameState->MaxGoblinOnMap)
	{
		SpawnNewGoblinWithTimer();
	}
	else
	{
		GetWorldTimerManager().ClearTimer(GoblinRespawnTimer);
	}
}

void AGoblinManager::SpawnNewGoblinWithTimer()
{
	AJeff1GameState* Jeff1GameState = GetWorld()->GetGameState<AJeff1GameState>();

	GetWorldTimerManager().SetTimer(
		GoblinRespawnTimer,
		this,
		&AGoblinManager::SpawnNewGoblin,
		FMath::FRandRange(0,Jeff1GameState->GoblinRespawnMaxTime),
		false);
}


void AGoblinManager::DespawnGoblin(AAiGoblinCharacter* Goblin)
{
	AJeff1GameState* Jeff1GameState = GetWorld()->GetGameState<AJeff1GameState>();

	Goblin->Destroy();
	Jeff1GameState->GoblinInMap--;
	if(Jeff1GameState->GoblinInMap==Jeff1GameState->MaxGoblinOnMap)
		SpawnNewGoblin();
	else
		SpawnNewGoblinWithTimer();
}

void AGoblinManager::IncreaseMaxGoblinLimit(int Increase)
{
	AJeff1GameState* Jeff1GameState = GetWorld()->GetGameState<AJeff1GameState>();

	if(Increase>0)
	{
		Jeff1GameState->MaxGoblinOnMap+=Increase;
		SpawnNewGoblin();
	}
}