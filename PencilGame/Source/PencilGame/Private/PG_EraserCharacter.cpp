// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_EraserCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PG_HealthComponent.h"
#include "PG_GameMode.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APG_EraserCharacter::APG_EraserCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NewSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("NewSpringArmComponent"));
	NewSpringArmComponent->bUsePawnControlRotation = true;
	NewSpringArmComponent->SetupAttachment(RootComponent);

	TPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TPS_CameraComponent"));
	TPSCameraComponent->SetupAttachment(NewSpringArmComponent);

	HealthComponent = CreateDefaultSubobject<UPG_HealthComponent>(TEXT("HealthComponent"));

	bIsInFreelookMode = false;
}

// Called when the game starts or when spawned
void APG_EraserCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLocation = GetActorLocation();

	GameModeReference = Cast<APG_GameMode>(GetWorld()->GetAuthGameMode());

	HealthComponent->OnHealthChangeDelegate.AddDynamic(this, &APG_EraserCharacter::OnHealthChange);
}

// Called every frame
void APG_EraserCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APG_EraserCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APG_EraserCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APG_EraserCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APG_EraserCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APG_EraserCharacter::StopJumping);

	PlayerInputComponent->BindAction("Freelook", IE_Pressed, this, &APG_EraserCharacter::ChangeFreelookMode);
	PlayerInputComponent->BindAction("Freelook", IE_Released, this, &APG_EraserCharacter::ChangeFreelookMode);
}

FVector APG_EraserCharacter::GetPawnViewLocation() const
{

	if (IsValid(TPSCameraComponent))
	{
		return TPSCameraComponent->GetComponentLocation();
	}

	return Super::GetPawnViewLocation();
}

void APG_EraserCharacter::PlayVictorySound()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), VictorySound, GetActorLocation());
}

void APG_EraserCharacter::MoveForward(float value)
{
	if (!bIsInFreelookMode)
	{
		AddMovementInput(GetActorForwardVector() * value);

	}
	else
	{
		BP_MoveFoward(value);
	}
}

void APG_EraserCharacter::MoveRight(float value)
{
	if (!bIsInFreelookMode)
	{
		AddMovementInput(GetActorRightVector() * value);
	}
	else
	{
		BP_MoveRight(value);
	}

}

void APG_EraserCharacter::Jump()
{
	Super::Jump();

	UGameplayStatics::PlaySoundAtLocation(GetWorld(), SmallJumpSound, GetActorLocation());
}

void APG_EraserCharacter::ChangeFreelookMode()
{
	if (bIsInFreelookMode)
	{
		bIsInFreelookMode = false;
		return;
	}
	else
	{
		bIsInFreelookMode = true;
		return;
	}
}

void APG_EraserCharacter::StopJumping()
{
	Super::StopJumping();
}

void APG_EraserCharacter::OnHealthChange(UPG_HealthComponent* MyHealthComponent, AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	OnDamageReceivedDelegate.Broadcast();
	if (HealthComponent->IsDead())
	{
		if (IsValid(GameModeReference))
		{
			GameModeReference->GameOver(this);
		}
	}
	else
	{
		BP_CameraShake();
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), HurtSound, GetActorLocation());
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_Respawn, this, &APG_EraserCharacter::RespawnCharacter, 2.5f, false);	
	}
}

void APG_EraserCharacter::RespawnCharacter()
{
	SetActorLocation(SpawnLocation);
}
