// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "XPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AXPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:
	float CurrentHP;

	float CurrentMP;

	float AttackDamage;

public:

	FORCEINLINE void SetCurrentHP(float hp) { this->CurrentHP = hp; }

	FORCEINLINE float GetCurrentHP() { return CurrentHP; }
	
	FORCEINLINE void SetCurrentMP(float mp) { this->CurrentMP = mp; }

	FORCEINLINE float GetCurrentMP() { return CurrentMP; }

	FORCEINLINE void SetAttackDamage(float ad) { this->AttackDamage = ad; }

	FORCEINLINE float GetAttackDamage() { return AttackDamage; }
	
	
};
