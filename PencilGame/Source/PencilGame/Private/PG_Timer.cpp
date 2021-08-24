// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_Timer.h"
#include "PG_GameMode.h"
#include "Kismet/GameplayStatics.h"

void UPG_Timer::InitializeWidget()
{
	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->OnGameOverDelegate.AddDynamic(this, &UPG_Timer::DeleteDueToEndGame);
		GameModeReference->OnVictoryDelegate.AddDynamic(this, &UPG_Timer::DeleteDueToEndGame);
	}
}

void UPG_Timer::DeleteDueToEndGame()
{
	BP_DeleteDueToEndGame();
}

