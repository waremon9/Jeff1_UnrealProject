// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"
#include "Knight.h"

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

	//get game state ref
	GameStateRef = GetWorld()->GetGameState<AJeff1GameState>();
    
    //update progress bar once at start
	FoodWidget->UpdateProgressBar(GameStateRef->GetFoodAcquired());

	//bind to delegate
	//THIS CAUSES THE CRASH
	KnightRef = Cast<AKnight>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	if(KnightRef)
	{
		KnightRef->Knight_OnFoodAcquired.AddDynamic(this, &AInGameHUD::RespondToFoodAcquiredDelegate);
	}
	
	
}

//doublon update progress bar
void AInGameHUD::RespondToFoodAcquiredDelegate(float Value)
{
	if(FoodWidget)
	{
		FoodWidget->UpdateProgressBar(Value);
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

void AInGameHUD::UpdateProgressBar(float Value)
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
