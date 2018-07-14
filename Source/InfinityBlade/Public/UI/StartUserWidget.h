// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "StartUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/* Start Game Button*/
	UPROPERTY()
		UButton* StartBtn;

	/* SignUp Button*/
	UPROPERTY()
		UButton* SignUpBtn;

	/* Exit Button*/
	UPROPERTY()
		UButton* ExitBtn; 
	
public:
	/* Initialize */
	virtual bool Initialize() override;

	/* Exit Game Click Event*/
	UFUNCTION()
		void ExitBtnOnClickedEvent();


};
