// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Sound/SoundCue.h"

void UPG_MainMenuWidget::InitializeWidget()
{
	if (!IsValid(MainMenuMusic))
	{
		return;
	}

	UGameplayStatics::PlaySound2D(GetWorld(), MainMenuMusic);
}

void UPG_MainMenuWidget::NewGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), GameplayLevelName);
}

void UPG_MainMenuWidget::GoToCredits()
{
}

void UPG_MainMenuWidget::QuitGame()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UKismetSystemLibrary::QuitGame(GetWorld(), PlayerController, EQuitPreference::Quit, false);
}
