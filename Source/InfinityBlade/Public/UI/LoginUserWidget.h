// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CircularThrobber.h"
#include "UI/MessageUserWidget.h"
#include "Components/EditableTextBox.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CustomGameInstance.h"
#include "LoginUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API ULoginUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY()
		UButton* BackBtn;
	UPROPERTY()
		UButton* LoginBtn;

	UPROPERTY()
		UEditableTextBox* UsernameInput;

	UPROPERTY()
		UEditableTextBox* PasswordInput;

	UPROPERTY()
		UMessageUserWidget* MessageWidget;

	UPROPERTY()
		UCircularThrobber* CircularThrobber;

	
public:
	UFUNCTION()
		virtual bool Initialize() override;
	UFUNCTION()
		void LoginBtnOnClickedEvent();

	void AccoutnLoginFromServer(FString Username, FString Password);

	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};
