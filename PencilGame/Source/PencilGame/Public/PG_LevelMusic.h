// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PG_LevelMusic.generated.h"

UCLASS()
class PENCILGAME_API APG_LevelMusic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APG_LevelMusic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
