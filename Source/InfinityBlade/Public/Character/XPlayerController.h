// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/XCharacter.h"
#include "UI/MainUserWidget.h"
#include "Weapon/Weapon.h"
#include "Character/XAnimInstance.h"
#include "CHaracter/XPlayerState.h"
#include "XPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AXPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY()
		AXCharacter* XCharacter;
	/* Character animation instance*/
	UPROPERTY()
		UXAnimInstance* XAnimInstance;

	UPROPERTY()
		AXPlayerState* XPlayerState;

	UPROPERTY()
		UMainUserWidget* MainWidget;
	UPROPERTY()
		AWeapon* XWeapon;

	
public:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
public:
	UFUNCTION()
		void MoveForward(float Speed);
	UFUNCTION()
		void MoveRight(float Speed);


	void InitState();

	void UpdateUI();

	/* Weapon Damage Func*/
	UFUNCTION()
		void WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult);

	void LockAI();

	void InitWidgetEvent();

	/* Attack Event*/
	UFUNCTION()
		void AttackBtnOnClickedEvent();
};
