// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "CameraMainMenu.generated.h"

UCLASS()
class JEFF1_API ACameraMainMenu : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USceneComponent* RootScene;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	
public:	
	// Sets default values for this actor's properties
	ACameraMainMenu();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
