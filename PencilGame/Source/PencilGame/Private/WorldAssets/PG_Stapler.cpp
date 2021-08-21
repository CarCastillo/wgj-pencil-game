// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldAssets/PG_Stapler.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
APG_Stapler::APG_Stapler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	RootComponent = CustomRootComponent;

	StaplerMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaplerMeshComponent"));
	StaplerMeshComponent->SetupAttachment(CustomRootComponent);

	StaplerColliderComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("StaplerColliderComponent"));
	StaplerColliderComponent->SetupAttachment(CustomRootComponent);
	StaplerColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaplerColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	StaplerColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	LaunchDirection = FVector(0, 0, 1500);
}

// Called when the game starts or when spawned
void APG_Stapler::BeginPlay()
{
	Super::BeginPlay();
	
}

void APG_Stapler::LaunchPlayer(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (IsValid(OtherActor))
	{
			ACharacter* OverlappedCharacter = Cast<ACharacter>(OtherActor);
			//Verifies if actor is a character
		if (IsValid(OverlappedCharacter))
		{
			PlayLaunchingSound();
		    OverlappedCharacter->LaunchCharacter(LaunchDirection, false, false);
		}
	}

}

void APG_Stapler::PlayLaunchingSound()
{
	if (!IsValid(LaunchingSound))
	{
		return;
	}

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), LaunchingSound, GetActorLocation());
}



