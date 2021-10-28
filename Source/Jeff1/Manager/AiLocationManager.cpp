// Fill out your copyright notice in the Description page of Project Settings.


#include "AiLocationManager.h"

#include "../Jeff1GameState.h"

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

	//Give ref to GameState
	AJeff1GameState* GS =  GetWorld()->GetGameState<AJeff1GameState>();
	if(GS)
	{
		GS->SetAiLocationManager(this);
	}
}

