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
}

void AGoblinManager::BeginPlay()
{
	Super::BeginPlay();

	Jeff1GameState = GetWorld()->GetGameState<AJeff1GameState>();


	if(Jeff1GameState==nullptr)
	{
		return;
	}
	
	//Give ref to GameState
	Jeff1GameState->SetGoblinManager(this);

	//Allow passing variable to function in timer
	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("IncreaseMaxGoblinLimit"), 1);

	//Set timer for max goblin increase
	GetWorldTimerManager().SetTimer(
		GoblinLimitIncreaseTimer,
		TimerDel,
		60.f,
		false);
}

//Spawn a new goblin and give it the right BT
void AGoblinManager::SpawnNewGoblin()
{	
	FActorSpawnParameters SpawnInfo;
	AAiGoblinCharacter* Goblin = GetWorld()->SpawnActor<AAiGoblinCharacter>(
		GoblinBP,
		Jeff1GameState->GetAiLocationManager()->GetBaseLocation()->GetActorLocation(),
		FRotator::ZeroRotator,
		SpawnInfo);

	AAiGoblinController* GoblinController = Cast<AAiGoblinController>(Goblin->Controller);

	if(GoblinController)
	{
		//check food in map
		if(Jeff1GameState->FoodInMap < Jeff1GameState->MaxFoodInMap)
		{
			//Create new food and give it to goblin
			GoblinController->SetFoodBT();
	
			TSubclassOf<AFood> FoodBp = Jeff1GameState->GetFoodBP();
			AFood* CreatedFood = GetWorld()->SpawnActor<AFood>(FoodBp, FVector::ZeroVector, FRotator::ZeroRotator, SpawnInfo);
	
			Goblin->CarryFood(CreatedFood);
			Jeff1GameState->FoodInMap++;
		}
		else
		{
			//Give goblin BT for not carrying food
			GoblinController->SetHandFreeBT();
		}
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

//Spawn a new goblin after random time
void AGoblinManager::SpawnNewGoblinWithTimer()
{
	GetWorldTimerManager().SetTimer(
		GoblinRespawnTimer,
		this,
		&AGoblinManager::SpawnNewGoblin,
		FMath::FRandRange(0,Jeff1GameState->GoblinRespawnMaxTime),
		false);
}


void AGoblinManager::DespawnGoblin(AAiGoblinCharacter* Goblin)
{
	Goblin->Destroy();
	Jeff1GameState->GoblinInMap--;
	if(Jeff1GameState->GoblinInMap==Jeff1GameState->MaxGoblinOnMap)
		SpawnNewGoblin();
	else
		SpawnNewGoblinWithTimer();
}

void AGoblinManager::IncreaseMaxGoblinLimit(int Increase)
{
	if(Increase>0)
	{
		Jeff1GameState->MaxGoblinOnMap+=Increase;
		SpawnNewGoblin();
	}
}