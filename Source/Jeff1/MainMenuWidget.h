// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	UMainMenuWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UFUNCTION()
	void PlayGame();
	UFUNCTION()
	void ExitGame();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ExitButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* PlayButton;
};
