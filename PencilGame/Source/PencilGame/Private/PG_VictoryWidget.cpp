// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_VictoryWidget.h"
#include "PG_GameMode.h"

void UPG_VictoryWidget::InitializeWidget()
{
	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->OnVictoryDelegate.AddDynamic(this, &UPG_VictoryWidget::OnVictory);
	}

	SetVisibility(ESlateVisibility::Hidden);
}

void UPG_VictoryWidget::OnVictory()
{
	SetVisibility(ESlateVisibility::Visible);
}
