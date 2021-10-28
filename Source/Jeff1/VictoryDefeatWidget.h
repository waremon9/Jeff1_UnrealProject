// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VictoryDefeatWidget.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API UVictoryDefeatWidget : public UUserWidget
{
	GENERATED_BODY()
	
	public:
	UVictoryDefeatWidget(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UFUNCTION()
	void RetryGame();
	UFUNCTION()
	void ExitGame();
	
	UFUNCTION()
	void SetText(FText Text, FLinearColor Color);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* RetryButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ExitButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* ResultText;
};
