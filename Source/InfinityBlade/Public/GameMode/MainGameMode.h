// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UI/MainUserWidget.h"
#include "Character/XCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Character/XPlayerController.h"
#include "Character/XPlayerState.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
		UMainUserWidget* MainWidget;

public:

	AMainGameMode();


	virtual void BeginPlay() override;
	
	
};
