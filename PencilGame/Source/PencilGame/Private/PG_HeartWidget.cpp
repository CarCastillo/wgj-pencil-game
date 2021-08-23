// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_HeartWidget.h"
#include "Math/UnrealMathUtility.h"
#include "PG_EraserCharacter.h"
#include "PG_GameMode.h"
#include "Kismet/GameplayStatics.h"

void UPG_HeartWidget::InitializeWidget()
{
	PlayerReference = Cast<APG_EraserCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	NumberOfLives = 5;

	if (IsValid(PlayerReference))
	{
		PlayerReference->OnDamageReceivedDelegate.AddDynamic(this, &UPG_HeartWidget::ReduceNumberOfLives);
	}

	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->OnGameOverDelegate.AddDynamic(this, &UPG_HeartWidget::DeleteDueToEndGame);
		GameModeReference->OnVictoryDelegate.AddDynamic(this, &UPG_HeartWidget::DeleteDueToEndGame);
	}
}

void UPG_HeartWidget::ReduceNumberOfLives()
{
	int OldNumOfLives = NumberOfLives;
	NumberOfLives = FMath::Clamp((OldNumOfLives-1), 0, 5);
}

void UPG_HeartWidget::DeleteDueToEndGame()
{
	BP_DeleteDueToEndGame();
}
