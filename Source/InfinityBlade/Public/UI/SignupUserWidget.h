// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Runtime/UMG/Public/Components/CircularThrobber.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "MessageUserWidget.h"
#include "SignupUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYBLADE_API USignupUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		UButton* BackBtn;
	UPROPERTY()
		UButton* SignupBtn;
	UPROPERTY()
		UEditableTextBox* UsernameInput;
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	UPROPERTY()
		UEditableTextBox* RePasswordInput;

	UPROPERTY()
		UCircularThrobber* CircularThrobber;

	UPROPERTY()
		UMessageUserWidget* MessageUserWidget;


public:
	virtual bool Initialize() override;
	
	UFUNCTION()
		void SignupBtnOnClickedEvent();

	void AccountSignupFromServer(FString &Username, FString &Password);

	void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
};
