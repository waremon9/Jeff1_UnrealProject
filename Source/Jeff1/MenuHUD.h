// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuWidget.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

	public:
	AMenuHUD();

	virtual void DrawHUD() override;
	virtual void BeginPlay() override;

	UFUNCTION()
	void PlayGame();
	UFUNCTION()
	void ExitGame();
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	private:
	UMainMenuWidget* MainMenuWidget;
};
