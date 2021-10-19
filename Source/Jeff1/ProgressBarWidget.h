// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "ProgressBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API UProgressBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//Widget constructor is not empty, it takes initializer as parameter
	UProgressBarWidget(const FObjectInitializer& ObjectInitializer);

	//basicaly a begingplay ==> for initialization purposes
	virtual void NativeConstruct() override;

	void UpdateProgressBar(int32 Value);

	void ResetProgressBar();

	//bindwidget enables binding by name, so no instanciate on this
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* CurrentFoodText;
};
