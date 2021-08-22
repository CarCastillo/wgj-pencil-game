// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_VictoryZone.h"
#include "Components/BoxComponent.h"
#include "PG_EraserCharacter.h"
#include "PG_GameMode.h"

// Sets default values
APG_VictoryZone::APG_VictoryZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VictoryZoneComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("VictoryZoneComponent"));
	RootComponent = VictoryZoneComponent;
	VictoryZoneComponent->SetBoxExtent(FVector(100.0f));
}

// Called when the game starts or when spawned
void APG_VictoryZone::BeginPlay()
{
	Super::BeginPlay();
	
	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());
}

void APG_VictoryZone::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (IsValid(OtherActor) && IsValid(GameModeReference))
	{
		APG_EraserCharacter* PGCharacter = Cast<APG_EraserCharacter>(OtherActor);

		if (IsValid(PGCharacter))
		{
			GameModeReference->Victory(PGCharacter);
		}
	}
}
