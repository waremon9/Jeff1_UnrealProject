// Fill out your copyright notice in the Description page of Project Settings.


#include "AiLocationManager.h"

#include "Jeff1GameState.h"

// Sets default values
AAiLocationManager::AAiLocationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAiLocationManager::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp,Error,TEXT("Begin of location manager"));


	if(GetWorld()->GetGameState<AJeff1GameState>())
	{
		
	GetWorld()->GetGameState<AJeff1GameState>()->SetAiLocationManager(this);
	}else
	{
		
		UE_LOG(LogTemp,Error,TEXT("NOPE"));
	}
}

