// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_MainMenuWidget.generated.h"

class USoundCue;

UCLASS()
class PENCILGAME_API UPG_MainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MainMenu")
	FName GameplayLevelName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* MainMenuMusic;

public:

	UFUNCTION(BlueprintCallable)
		void InitializeWidget();

protected:

	UFUNCTION(BlueprintCallable, Category = "MainMenu")
	void NewGame();

	UFUNCTION(BlueprintCallable, Category = "MainMenu")
	void GoToCredits();

	UFUNCTION(BlueprintCallable, Category = "MainMenu")
	void QuitGame();
};
