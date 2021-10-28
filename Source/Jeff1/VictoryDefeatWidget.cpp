// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryDefeatWidget.h"

#include "Jeff1GameInstance.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"


class UJeff1GameInstance;

UVictoryDefeatWidget::UVictoryDefeatWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UVictoryDefeatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ExitButton->OnClicked.AddDynamic(this, &UVictoryDefeatWidget::ExitGame);
	RetryButton->OnClicked.AddDynamic(this, &UVictoryDefeatWidget::RetryGame);
}

void UVictoryDefeatWidget::RetryGame()
{
	UJeff1GameInstance* GI = GetGameInstance<UJeff1GameInstance>();
	if(GI)
	{
		UGameplayStatics::OpenLevel(this, GI->GetNextLevelName(), true);
	}
}

void UVictoryDefeatWidget::ExitGame()
{
	APlayerController* SpecificPlayer  = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), SpecificPlayer, EQuitPreference::Quit,true);
}

void UVictoryDefeatWidget::SetText(FText Text, FLinearColor Color)
{
	ResultText->SetText(Text);
	ResultText->SetColorAndOpacity(Color);
}
