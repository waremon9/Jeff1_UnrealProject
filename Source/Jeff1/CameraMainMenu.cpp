// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraMainMenu.h"

// Sets default values
ACameraMainMenu::ACameraMainMenu()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootScene);

}

// Called when the game starts or when spawned
void ACameraMainMenu::BeginPlay()
{
	Super::BeginPlay();

	if(Camera)
	{
		GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
	}
	
}


