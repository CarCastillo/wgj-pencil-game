// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PG_LevelMusic.generated.h"

class UAudioComponent;
class UBillboardComponent;
class APG_GameMode;
class APG_Character;

UCLASS()
class PENCILGAME_API APG_LevelMusic : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBillboardComponent* MusicBillboardComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* MusicAudioComponent;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "References")
	APG_GameMode* GameModeReference;
	
public:	
	// Sets default values for this actor's properties
	APG_LevelMusic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void StopLevelMusic();

};
