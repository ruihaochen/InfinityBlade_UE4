// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Animation/AnimInstance.h"
#include "Character/XPlayerState.h"

#include "XAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UXAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		AXPlayerState* XPlayerState;
	/* Character base info*/
	UPROPERTY()
	float NormalAttack;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	/* is Attacking status*/
	bool bIsAttacking;
	/* Playing status*/
	bool bIsPlaying;
	/* Can Enter Second Attack*/
	bool bIsEnableSecondAttack;
	bool bIsEnableThirdAttack;
	bool bIsEnableFourthAttack;
	bool bIsEnableFifthAttack;

public:

	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();


	

	UFUNCTION()
		void AnimNotify_PlayStart(UAnimNotify* Notify);

	UFUNCTION()
		void AnimNotify_PlayEnd(UAnimNotify* Notify);

	/* Attack Start Montage*/
	UFUNCTION()
		void AnimNotify_AttackStart(UAnimNotify* Notify);
	/* Attack End Montage*/
	UFUNCTION()
		void AnimNotify_AttackEnd(UAnimNotify* Notify);

	/* Reset Attack Status*/
	UFUNCTION()
		void AnimNotify_ResetSerialAttack(UAnimNotify* Notify);

	/* Can Enter Second Attack*/
	UFUNCTION()
		void AnimNotify_SecondAttackInput(UAnimNotify* Notify);
	/* Can Enter Third Attack*/
	UFUNCTION()
		void AnimNotify_ThirdAttackInput(UAnimNotify* Notify);
	/* Can Enter Fourth Attack*/
	UFUNCTION()
		void AnimNotify_FourthAttackInput(UAnimNotify* Notify);
	/* Can Enter Fifth Attack*/
	UFUNCTION()
		void AnimNotify_FifthAttackInput(UAnimNotify* Notify);

	void InitState();
	
	void ResetAttackDamage();

	void UpdateDamage();
};
