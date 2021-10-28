// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "FoodCarryingCharacter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "InGameHUD.h"
#include "Delegates/Delegate.h"
#include "Knight.generated.h"

UCLASS(config=Game)
class JEFF1_API AKnight : public AFoodCarryingCharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere)
	USceneCaptureComponent2D* FaceCamera;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxInteract;

	UPROPERTY(VisibleAnywhere)
	UAnimBlueprint* AnimComp;

public:
	AKnight();
	
	virtual void BeginPlay() override;

	//delegate on foodacquired
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKnightFoodAcquired, float, Value);

	//event name
	FKnightFoodAcquired Knight_OnFoodAcquired;
	
protected:

	AInGameHUD* InGameHUDRef;
	
	UFUNCTION()
	void MoveForward(float value);
	
	UFUNCTION()
	void MoveRight(float value);

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void CameraZoomIn();
	UFUNCTION()
	void CameraZoomOut();
	UPROPERTY(VisibleAnywhere)
	float CameraZoom_v;
	UPROPERTY(EditAnywhere)
	float ZoomSpeed = 25.f;
	UPROPERTY(EditAnywhere)
	float MinCameraLength = 150.f;
	UPROPERTY(EditAnywhere)
	float MaxCameraLength = 800.f;

	UFUNCTION()
	void InteractNoFoodInHand();
	UFUNCTION()
	void InteractFoodInHand();

	public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
