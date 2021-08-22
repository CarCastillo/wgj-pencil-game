// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_BorradoraIconWidget.h"
#include "PG_EraserCharacter.h"
#include "PG_GameMode.h"
#include "Kismet/GameplayStatics.h"

void UPG_BorradoraIconWidget::InitializeWidget()
{
	PlayerReference = Cast<APG_EraserCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->OnGameOverDelegate.AddDynamic(this, &UPG_BorradoraIconWidget::DeleteDueToGameOver);
	}

	if (IsValid(PlayerReference))
	{
		PlayerReference->OnDamageReceivedDelegate.AddDynamic(this, &UPG_BorradoraIconWidget::ChangeToDamagedIcon);
	}
}

void UPG_BorradoraIconWidget::ChangeToDamagedIcon()
{
	BP_ChangeToDamagedIcon();
}

void UPG_BorradoraIconWidget::DeleteDueToGameOver()
{
	BP_DeleteDueToGameOver();
}
