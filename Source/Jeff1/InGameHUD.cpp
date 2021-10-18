// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"

AInGameHUD::AInGameHUD()
{
	
}

void AInGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if(FoodWidgetClass)
	{
		FoodWidget = CreateWidget<UProgressBarWidget>(GetWorld(), FoodWidgetClass);
		if(FoodWidget)
		{
			//if it went well then add to viewport
			FoodWidget->AddToViewport();
		}
	}
}

void AInGameHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AInGameHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AInGameHUD::UpdateProgressBar(int32 Value)
{
	if(FoodWidget)
	{
		FoodWidget->UpdateProgressBar(Value);
	}
}

void AInGameHUD::ResetProgressBar()
{
	if(FoodWidget)
	{
		FoodWidget->ResetProgressBar();
	}
}
