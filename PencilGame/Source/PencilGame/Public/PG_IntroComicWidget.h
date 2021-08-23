// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_IntroComicWidget.generated.h"

class USoundCue;

UCLASS()
class PENCILGAME_API UPG_IntroComicWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "IntroComic")
	FName GameplayLevelName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* IntroComicMusic;

public:

	UFUNCTION(BlueprintCallable)
	void InitializeWidget();

protected:

	UFUNCTION(BlueprintCallable, Category = "IntroComic")
	void StartGameplay();
	
};
