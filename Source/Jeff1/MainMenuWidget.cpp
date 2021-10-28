// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "Jeff1GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

UMainMenuWidget::UMainMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::ExitGame);
	PlayButton->OnClicked.AddDynamic(this, &UMainMenuWidget::PlayGame);
}

void UMainMenuWidget::PlayGame()
{
	UGameplayStatics::OpenLevel(this, GetGameInstance<UJeff1GameInstance>()->GetNextLevelName(), true);
}

void UMainMenuWidget::ExitGame()
{
	APlayerController* SpecificPlayer  = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), SpecificPlayer, EQuitPreference::Quit,true);
}
