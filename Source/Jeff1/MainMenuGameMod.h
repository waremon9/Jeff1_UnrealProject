// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainMenuGameMod.generated.h"

/**
 * 
 */
UCLASS()
class JEFF1_API AMainMenuGameMod : public AGameMode
{
	GENERATED_BODY()

	public:
	AMainMenuGameMod();

	void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	ACameraActor* MenuCamera;
	
};
