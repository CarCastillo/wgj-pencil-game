// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PG_GameMode.generated.h"

class APG_EraserCharacter;

UCLASS()
class PENCILGAME_API APG_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Flow")
		FName GameOverMapName;

protected:

	virtual void BeginPlay() override;

public:

	APG_GameMode();

	UFUNCTION()
	void GameOver(APG_EraserCharacter* Character);
};
