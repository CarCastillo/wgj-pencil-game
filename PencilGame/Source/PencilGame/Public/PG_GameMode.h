// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PG_GameMode.generated.h"

class APG_EraserCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStateChangeSignature);

UCLASS()
class PENCILGAME_API APG_GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	FTimerHandle TimerHandle_NotifyGameOver;

	FTimerHandle TimerHandle_NotifyVictory;

public:

	UPROPERTY(BlueprintAssignable)
	FOnGameStateChangeSignature OnVictoryDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnGameStateChangeSignature OnGameOverDelegate;

protected:

	virtual void BeginPlay() override;

	void NotifyGameOver();

	void NotifyVictory();

public:

	APG_GameMode();

	UFUNCTION()
	void GameOver(APG_EraserCharacter* Character);

	UFUNCTION()
	void Victory(APG_EraserCharacter* Character);
};
