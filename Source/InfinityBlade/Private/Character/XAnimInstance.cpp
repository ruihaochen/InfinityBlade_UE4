// Fill out your copyright notice in the Description page of Project Settings.

#include "XAnimInstance.h"
#include "Character/XPlayerController.h"

void UXAnimInstance::UpdateSpeed()
{
	if (TryGetPawnOwner() != nullptr)
	{
		Speed = TryGetPawnOwner()->GetVelocity().Size();
	}
}

void UXAnimInstance::AnimNotify_PlayStart(UAnimNotify * Notify)
{
	bIsPlaying = true;
}

void UXAnimInstance::AnimNotify_PlayEnd(UAnimNotify* Notify)
{
	bIsPlaying = false;
}

void UXAnimInstance::AnimNotify_AttackStart(UAnimNotify* Notify)
{
	bIsAttacking = true;
}

void UXAnimInstance::AnimNotify_AttackEnd(UAnimNotify* Notify)
{
	bIsAttacking = false;
}

void UXAnimInstance::AnimNotify_ResetSerialAttack(UAnimNotify * Notify)
{
	bIsEnableSecondAttack = false;
	bIsEnableThirdAttack = false;
	bIsEnableFourthAttack = false;
	bIsEnableFifthAttack = false;
	ResetAttackDamage();
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Blue, FString::SanitizeFloat(XPlayerState->GetAttackDamage()));

}

void UXAnimInstance::AnimNotify_SecondAttackInput(UAnimNotify* Notify)
{
	bIsEnableSecondAttack = true;
	UpdateDamage();

	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Blue, FString::SanitizeFloat(XPlayerState->GetAttackDamage()));
}

void UXAnimInstance::AnimNotify_ThirdAttackInput(UAnimNotify * Notify)
{
	bIsEnableThirdAttack = true;
	UpdateDamage();
	
}

void UXAnimInstance::AnimNotify_FourthAttackInput(UAnimNotify * Notify)
{
	bIsEnableFourthAttack = true;
	UpdateDamage();
}

void UXAnimInstance::AnimNotify_FifthAttackInput(UAnimNotify* Notify)
{
	bIsEnableFifthAttack = true;
	UpdateDamage();
}

void UXAnimInstance::InitState()
{
	if (XPlayerState==nullptr)
	{
		AXPlayerController* XPlayerController = Cast<AXPlayerController>(TryGetPawnOwner()->GetController());

		/* Get state*/

		XPlayerState = XPlayerController->XPlayerState;

		NormalAttack = XPlayerState->GetAttackDamage();
	}
	
}

void UXAnimInstance::ResetAttackDamage()
{
	InitState();
	/* Reset Attack*/
	XPlayerState->SetAttackDamage(NormalAttack);
}

void UXAnimInstance::UpdateDamage()
{
	InitState();
	XPlayerState->SetAttackDamage(XPlayerState->GetAttackDamage() + 10.f);
}
