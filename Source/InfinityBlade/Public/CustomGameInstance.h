// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/LoadUserWidget.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	/* Store User Data*/
	TMap<FString, FString> ContextMap;

	UPROPERTY()
		ULoadUserWidget* LoadUserWidget;
	
public:
	virtual void Init() override;

	UFUNCTION()
		void PreLoadMap(const FString & Map);

	UFUNCTION()
		void PostLoadMap(UWorld* World);

	UFUNCTION(BlueprintCallable, Category = LoadFunction)
		bool GetLoadStatus();
	
};
