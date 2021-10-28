// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMod.h"

#include "Camera/CameraActor.h"

AMainMenuGameMod::AMainMenuGameMod()
{
}

void AMainMenuGameMod::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}
