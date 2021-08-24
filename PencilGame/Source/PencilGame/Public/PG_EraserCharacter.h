// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PG_EraserCharacter.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageReceivedSignature, float, CurrentHealth);

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UPG_HealthComponent;
class APG_GameMode;
class USoundCue;

UCLASS()
class PENCILGAME_API APG_EraserCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* NewSpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* TPSCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPG_HealthComponent* HealthComponent;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera Movement")
	bool bIsInFreelookMode;

	FVector SpawnLocation;

	FTimerHandle TimerHandle_Respawn;
	
	APG_GameMode* GameModeReference;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* SmallJumpSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* VictorySound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio")
	USoundCue* HurtSound;

public:
	UPROPERTY(BlueprintAssignable)
	FOnDamageReceivedSignature OnDamageReceivedDelegate;
public:
	// Sets default values for this character's properties
	APG_EraserCharacter();

	virtual FVector GetPawnViewLocation() const override;

	void PlayVictorySound();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_MoveFoward(float value);

	void MoveRight(float value);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_MoveRight(float value);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_CameraShake();

	virtual void Jump() override;
	
	void ChangeFreelookMode();

	virtual void StopJumping() override;

	UFUNCTION()
	void OnHealthChange(UPG_HealthComponent* MyHealthComponent, AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	void RespawnCharacter();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
