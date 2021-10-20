// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FaceCameraWidget.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API UFaceCameraWidget : public UUserWidget
{
	GENERATED_BODY()
	
	protected:
	//Widget constructor is not empty, it takes initializer as parameter
	UFaceCameraWidget(const FObjectInitializer& ObjectInitializer);
	
	//basicaly a begingplay ==> for initialization purposes
	virtual void NativeConstruct() override;
};
