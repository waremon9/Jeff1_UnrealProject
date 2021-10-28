// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

AMenuHUD::AMenuHUD()
{
}

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if(MainMenuWidgetClass)
	{
		MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
		if(MainMenuWidget)
		{
			MainMenuWidget->AddToViewport();
		}
	}
}

void AMenuHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AMenuHUD::ExitGame()
{
	if(MainMenuWidget)
	{
		MainMenuWidget->ExitGame();
	}
}

void AMenuHUD::PlayGame()
{
	if(MainMenuWidget)
	{
		MainMenuWidget->PlayGame();
	}
}
