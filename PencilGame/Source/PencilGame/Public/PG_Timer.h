// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_Timer.generated.h"

/**
 * 
 * 
 * 
 */

class APG_GameMode;

UCLASS()
class PENCILGAME_API UPG_Timer : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Reference")
	APG_GameMode* GameModeReference;
	
protected:

	UFUNCTION(BlueprintCallable)
	void InitializeWidget();

	UFUNCTION()
	void DeleteDueToEndGame();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_DeleteDueToEndGame();
};
