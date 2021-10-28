// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FaceCameraWidget.h"
#include "Jeff1GameState.h"
#include "GameFramework/HUD.h"
#include "ProgressBarWidget.h"
#include "VictoryDefeatWidget.h"
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

	virtual void BeginPlay() override;
	
	UFUNCTION()
		void UpdateProgressBar(float Value);

	UFUNCTION()
		void ResetProgressBar();

	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UUserWidget> FoodWidgetClass;
	
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UUserWidget> FaceCameraWidgetClass;
	
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UUserWidget> VictoryDefeatWidgetClass;

	UPROPERTY()
	AJeff1GameState* GameStateRef;

	UFUNCTION()
	void GameEnded(bool Victory);

protected:
	AKnight* KnightRef;
	
private:
	UProgressBarWidget* FoodWidget;
	UFaceCameraWidget* FaceCameraWidget;
	UVictoryDefeatWidget* VictoryDefeatWidget;
};
