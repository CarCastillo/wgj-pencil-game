// Fill out your copyright notice in the Description page of Project Settings.


#include "PG_EraserCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APG_EraserCharacter::APG_EraserCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);

	TPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TPS_CameraComponent"));
	TPSCameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void APG_EraserCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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
}

FVector APG_EraserCharacter::GetPawnViewLocation() const
{

	if (IsValid(TPSCameraComponent))
	{
		return TPSCameraComponent->GetComponentLocation();
	}

	return Super::GetPawnViewLocation();
}

void APG_EraserCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void APG_EraserCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void APG_EraserCharacter::Jump()
{
	Super::Jump();
}

void APG_EraserCharacter::StopJumping()
{
	Super::StopJumping();
}
