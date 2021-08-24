// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_HeartWidget.generated.h"

class APG_EraserCharacter;
class APG_GameMode;

/**
 * 
 */
UCLASS()
class PENCILGAME_API UPG_HeartWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Reference")
	APG_GameMode* GameModeReference;

	UPROPERTY(BlueprintReadOnly, Category = "Reference")
	APG_EraserCharacter* PlayerReference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lives")
	int NumberOfLives;

protected:
	
	UFUNCTION(BlueprintCallable)
	void InitializeWidget();

	UFUNCTION()
	void ReduceNumberOfLives(float CurrentHealth);


	UFUNCTION()
	void DeleteDueToEndGame();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_DeleteDueToEndGame();
	
};
