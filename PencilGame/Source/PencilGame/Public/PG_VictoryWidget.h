// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_VictoryWidget.generated.h"

class APG_GameMode;
class USoundCue;

UCLASS()
class PENCILGAME_API UPG_VictoryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	APG_GameMode* GameModeReference;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* WinSound;

public:

	UFUNCTION(BlueprintCallable)
	void InitializeWidget();

	UFUNCTION()
	void OnVictory();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnVictory();
	
};
