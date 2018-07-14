// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UI/StartUserWidget.h"
#include "UI/SignupUserWidget.h"
#include "UI/LoginUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * Game Start Game Mode
 */
UCLASS()
class INFINITYBLADE_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()
	

public: 
	UPROPERTY()
		UStartUserWidget* StartWidget;

	UPROPERTY()
		USignupUserWidget* SignupWidget;

	UPROPERTY()
		ULoginUserWidget* LoginWidget;
public:
	virtual void BeginPlay() override;
	
	UFUNCTION()
		void SignupBtnOnClickedEvent();

	UFUNCTION()
		void StartBtnOnClickedEvent();

	UFUNCTION()
		void SignupBackBtnOnClickedEvent();

	UFUNCTION()
		void LoginBackBtnOnClickedEvent();
};
