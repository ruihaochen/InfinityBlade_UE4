// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "COmponents/ProgressBar.h"
#include "MainUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* ProgressBar_HP;
	UPROPERTY(Meta = (BindWidget))
		UProgressBar* ProgressBar_MP;

	UPROPERTY()
		UButton* BtnAttack;

	
public:
	/* Initialize */
	virtual bool Initialize() override;
};
