// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Weapon/Weapon.h"
#include "Animation/AnimMontage.h"
#include "XCharacter.generated.h"


/* Main Character Class*/
UCLASS()
class INFINITYBLADE_API AXCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	/* HP*/
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalHP;
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float TotalMP;
	UPROPERTY(EditAnywhere, Category = "PlayerState")
		float NormalAttack;

	UPROPERTY(EditAnywhere, Category = "Montage")
		UAnimMontage* SerialAttackMontage;

public:

	UPROPERTY(EditAnywhere)
		UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		TSubclassOf<AWeapon> XWeaponClass;


	// Sets default values for this character's properties
	AXCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
