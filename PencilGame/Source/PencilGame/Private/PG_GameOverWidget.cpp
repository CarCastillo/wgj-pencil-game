// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_GameOverWidget.h"
#include "PG_GameMode.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

void UPG_GameOverWidget::InitializeWidget()
{
	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->OnGameOverDelegate.AddDynamic(this, &UPG_GameOverWidget::OnGameOver);
	}

	SetVisibility(ESlateVisibility::Hidden);
}

void UPG_GameOverWidget::OnGameOver()
{
	UGameplayStatics::PlaySound2D(GetWorld(), GameOverSound);
	SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_CloseScreen, this, &UPG_GameOverWidget::GoToMainMenu, 5.5f, false);
}

void UPG_GameOverWidget::GoToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenuMap");
}
