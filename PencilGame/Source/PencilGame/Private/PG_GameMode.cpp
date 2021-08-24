// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_GameMode.h"
#include "PG_EraserCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

APG_GameMode::APG_GameMode()
{
}

void APG_GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void APG_GameMode::GameOver(APG_EraserCharacter* Character)
{
	Character->DisableInput(nullptr);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_NotifyGameOver, this, &APG_GameMode::NotifyGameOver, 2.0f, false);
}

void APG_GameMode::NotifyGameOver()
{
	OnGameOverDelegate.Broadcast();
}

void APG_GameMode::Victory(APG_EraserCharacter* Character)
{
	Character->DisableInput(nullptr);
	Character->SetHasWonGame(true);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_NotifyVictory, this, &APG_GameMode::NotifyVictory, 2.0f, false);
}

void APG_GameMode::NotifyVictory()
{
	OnVictoryDelegate.Broadcast();
}
