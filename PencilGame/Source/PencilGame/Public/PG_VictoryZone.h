// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PG_VictoryZone.generated.h"

class UBoxComponent;
class APG_GameMode;

UCLASS()
class PENCILGAME_API APG_VictoryZone : public AActor
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* VictoryZoneComponent;

protected:

	APG_GameMode* GameModeReference;

public:	
	// Sets default values for this actor's properties
	APG_VictoryZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
