// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_IntroComicWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Sound/SoundCue.h"

void UPG_IntroComicWidget::InitializeWidget()
{
	if (!IsValid(IntroComicMusic))
	{
		return;
	}

	UGameplayStatics::PlaySound2D(GetWorld(), IntroComicMusic);
}

void UPG_IntroComicWidget::StartGameplay()
{

}
