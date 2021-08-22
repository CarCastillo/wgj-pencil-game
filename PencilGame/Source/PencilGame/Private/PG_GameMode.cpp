// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_GameMode.h"
#include "PG_EraserCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

APG_GameMode::APG_GameMode()
{
	GameOverMapName = "GameOverMap";
}

void APG_GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void APG_GameMode::GameOver(APG_EraserCharacter* Character)
{
	Character->GetMovementComponent()->StopMovementImmediately();
	Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Character->DisableInput(nullptr);

	UE_LOG(LogTemp, Warning, TEXT("GAME OVER!!!"));
}
