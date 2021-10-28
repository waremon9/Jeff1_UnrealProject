// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FoodCarryingCharacter.h"
#include "Knight.h"
#include "AiGoblinCharacter.generated.h"

UCLASS()
class JEFF1_API AAiGoblinCharacter : public AFoodCarryingCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AAiGoblinCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	float GetDistanceSight() const;
	float GetSideSight() const;
	AKnight* GetTarget() const;
	void SetWatchForKnight(bool _value);
	void StopMovingTowards();
	UFUNCTION()
	void SetMovingTowards(const FVector& _KnightDirection);

private:
	UPROPERTY(VisibleAnywhere)
	AKnight* Knight;

	UPROPERTY(VisibleAnywhere)
	float DistanceSight = 1000;

	UPROPERTY(VisibleAnywhere)
	float SideSight = 135;

	UPROPERTY(VisibleAnywhere)
	bool WatchesForKnight = true;
	bool bIsMovingTowards;
	FVector KnightDirection;
};