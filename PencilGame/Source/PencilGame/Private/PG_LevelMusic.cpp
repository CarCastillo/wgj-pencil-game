// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_LevelMusic.h"

// Sets default values
APG_LevelMusic::APG_LevelMusic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APG_LevelMusic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APG_LevelMusic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

