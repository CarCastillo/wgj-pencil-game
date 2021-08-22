// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PG_BorradoraIconWidget.generated.h"

/**
 * 
 */

class APG_GameMode;
class APG_EraserCharacter;

UCLASS()
class PENCILGAME_API UPG_BorradoraIconWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Reference")
	APG_GameMode* GameModeReference;

	UPROPERTY(BlueprintReadOnly, Category = "Reference")
	APG_EraserCharacter* PlayerReference;

protected:

	UFUNCTION(BlueprintCallable)
	void InitializeWidget();

	UFUNCTION()
	void ChangeToDamagedIcon();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_ChangeToDamagedIcon();

    UFUNCTION()
	void DeleteDueToGameOver();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_DeleteDueToGameOver();

	
};
