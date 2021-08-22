// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_LevelMusic.h"
#include "Components/AudioComponent.h"
#include "Components/BillboardComponent.h"
#include "PG_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PG_EraserCharacter.h"

// Sets default values
APG_LevelMusic::APG_LevelMusic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MusicBillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("MusicBillboardComponent"));
	RootComponent = MusicBillboardComponent;

	MusicAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicAudioComponent"));
	MusicAudioComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APG_LevelMusic::BeginPlay()
{
	Super::BeginPlay();
	
	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	if (IsValid(GameModeReference))
	{
		GameModeReference->OnVictoryDelegate.AddDynamic(this, &APG_LevelMusic::StopLevelMusic);
		GameModeReference->OnGameOverDelegate.AddDynamic(this, &APG_LevelMusic::StopLevelMusic);
	}
}

void APG_LevelMusic::StopLevelMusic()
{
	MusicAudioComponent->Stop();
}
