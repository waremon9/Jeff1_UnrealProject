// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressBarWidget.h"

UProgressBarWidget::UProgressBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UProgressBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	FoodRequired = GetWorld()->GetGameState<AJeff1GameState>()->GetFoodRequired();
	UE_LOG(LogTemp, Warning, TEXT("%d"), FoodRequired);
}


void UProgressBarWidget::UpdateProgressBar(float Value)
{
	if(CurrentFoodText)
	{
		//if for some reason the text is hidden, show it
		if(CurrentFoodText->Visibility == ESlateVisibility::Hidden)
		{
			CurrentFoodText->SetVisibility(ESlateVisibility::Visible);
		}
		//update text with value passed as parameter
		CurrentFoodText->SetText(FText::FromString(FString::FromInt(Value)));

		FoodProgressBar->SetPercent((Value/FoodRequired));
	}
}

//if you reset level call this
void UProgressBarWidget::ResetProgressBar()
{
	if(CurrentFoodText)
	{
		CurrentFoodText->SetVisibility(ESlateVisibility::Hidden);
	}
}

