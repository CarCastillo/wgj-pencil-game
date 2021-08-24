// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_GameOverWidget.generated.h"

class APG_GameMode;
class USoundCue;

UCLASS()
class PENCILGAME_API UPG_GameOverWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	APG_GameMode* GameModeReference;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* GameOverSound;

	FTimerHandle TimerHandle_CloseScreen;

public:

	UFUNCTION(BlueprintCallable)
	void InitializeWidget();

	UFUNCTION()
	void OnGameOver();
	
	UFUNCTION()
	void GoToMainMenu();
};
