// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"

#include "GameMenuBuilder/Public/GameMenuItem.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	RootComponent = RootScene;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
	if(PossibleFoodArray.Num()>0)
	{
		//Set A random mesh to the food
		StaticMesh->SetStaticMesh(PossibleFoodArray[FMath::RandRange(0, PossibleFoodArray.Num() - 1)]);
		FVector Min;
		FVector Max;
		StaticMesh->GetLocalBounds(Min, Max);
		
		//Adjust mesh size
		StaticMesh->SetWorldScale3D(RootScene->GetComponentScale() / ((Max.X - Min.X) / SizeGoal));

	}
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

