// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Knight.h"
#include "GameFramework/Actor.h"
#include "Chest.generated.h"

UCLASS()
class JEFF1_API AChest : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseChest;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TopChest;
	
	
public:	
	// Sets default values for this actor's properties
	AChest();

	UPROPERTY(EditAnywhere)
	float ChestMaxAngle;
	UPROPERTY(EditAnywhere)
	float MinDistanceKnight;
	UPROPERTY(EditAnywhere)
	float MaxDistanceKnight;

	UPROPERTY(VisibleDefaultsOnly)
	FRotator BaseTopRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
	AKnight* Knight;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
