// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_GameOverWidget.h"
#include "PG_GameMode.h"

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
	SetVisibility(ESlateVisibility::Visible);
}