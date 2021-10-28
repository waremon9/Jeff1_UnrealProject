// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoblinManager.generated.h"

UCLASS()
class JEFF1_API AGoblinManager : public AActor
{
	GENERATED_BODY()
	
	//Goblin blueprint
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AAiGoblinCharacter> GoblinBP;

	UPROPERTY()
	FTimerHandle GoblinRespawnTimer;
	UPROPERTY()
	FTimerHandle GoblinLimitIncreaseTimer;
	
public:	
	// Sets default values for this actor's properties
	AGoblinManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void SpawnNewGoblinWithTimer();
	UFUNCTION()
	void IncreaseMaxGoblinLimit(int Increase);

public:
	
	UFUNCTION()
	void SpawnNewGoblin();
	UFUNCTION()
	void DespawnGoblin(AAiGoblinCharacter* Goblin);
	
	UFUNCTION()
	TSubclassOf<class AAiGoblinCharacter> GetGoblinBP(){return GoblinBP;}

};
