// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MessageUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UMessageUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		UButton* CloseBtn;

	UPROPERTY()
		UTextBlock* MessageBlock;
public:

	virtual bool Initialize() override;

	UFUNCTION()
		void CloseBtnOnClickedEvent();
};
