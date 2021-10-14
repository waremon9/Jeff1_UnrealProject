// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"

#include "Knight.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	RootComponent = RootScene;

	BaseChest = CreateDefaultSubobject<UStaticMeshComponent>("BaseOfChest");
	BaseChest->SetupAttachment(RootScene);
	TopChest = CreateDefaultSubobject<UStaticMeshComponent>("TopPartOfChest");
	TopChest->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> Knights;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AKnight::StaticClass(), Knights);

	if(Knights.Num()>0) Knight = Cast<AKnight>(Knights[0]);
	UE_LOG(LogTemp, Warning, TEXT("%d"), Knights.Num());

	BaseTopRotation = TopChest->GetRelativeRotation();
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(Knight)
	{
		float Dist = FVector::Distance(Knight->GetActorLocation(), this->GetActorLocation());
		float angle;

		if(Dist<MinDistanceKnight) angle = ChestMaxAngle;
		else if (Dist>MaxDistanceKnight) angle = 0;
		else
		{
			angle = ChestMaxAngle * (1-(Dist-MinDistanceKnight) / (MaxDistanceKnight - MinDistanceKnight));
		}

		TopChest->SetRelativeRotation(FRotator(0,0,angle) + BaseTopRotation);
	}
}

