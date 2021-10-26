// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Jeff1GameState.h"
#include "GameFramework/HUD.h"
#include "ProgressBarWidget.h"
#include "InGameHUD.generated.h"

/**
 * 
 */

class AKnight;

UCLASS()
class JEFF1_API AInGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AInGameHUD();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
		void UpdateProgressBar(float Value);

	UFUNCTION()
		void ResetProgressBar();

	UFUNCTION()
		void RespondToFoodAcquiredDelegate(float Value);

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
		TSubclassOf<UUserWidget> FoodWidgetClass;

	AJeff1GameState* GameStateRef;

protected:
	AKnight* KnightRef;
	
private:
	UProgressBarWidget* FoodWidget;
};
