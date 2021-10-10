// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	RootComponent = RootScene;

	BaseChest = CreateDefaultSubobject<UStaticMeshComponent>("BaseOfChest");
	BaseChest->SetupAttachment(RootScene);
	TopChest = CreateDefaultSubobject<UStaticMeshComponent>("TopPartOfChest");
	TopChest->SetupAttachment(RootScene);

}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

