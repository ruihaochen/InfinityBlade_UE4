// Fill out your copyright notice in the Description page of Project Settings.

#include "SignupUserWidget.h"




bool USignupUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));

	UsernameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TextBox_Username")));

	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TextBox_Password")));

	RePasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TextBox_RePassword")));

	SignupBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_SignUp")));

	SignupBtn->OnClicked.AddDynamic(this, &USignupUserWidget::SignupBtnOnClickedEvent);

	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Loading")));

	MessageUserWidget = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageUserWidget")));

	return true;
}

void USignupUserWidget::SignupBtnOnClickedEvent()
{
	FString Username = UsernameInput->GetText().ToString();

	FString Password = PasswordInput->GetText().ToString();

	FString RePassword = RePasswordInput->GetText().ToString();

	if (Username.Len() < 2 || Username.Len() > 8)
	{
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MessageBlock->SetText(FText::FromString("Username is not available!(2-8)"));
		return;
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Username Length incorrect");
	}

	if (!Password.Equals(RePassword))
	{
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MessageBlock->SetText(FText::FromString("Passwords are not the same"));
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Two passwords don't match");
		return;
	
	}
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Username+":"+Password+":"+RePassword);

	CircularThrobber->SetVisibility(ESlateVisibility::Visible);

	SignupBtn->SetIsEnabled(false);

	AccountSignupFromServer(Username, Password);

}

void USignupUserWidget::AccountSignupFromServer(FString &Username, FString &Password)
{
	FString SignupInfo;
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&SignupInfo);
	/* start input data into json writer*/
	JsonWriter->WriteObjectStart();

	JsonWriter->WriteValue("nickname", Username);

	JsonWriter->WriteValue("password", Password);

	JsonWriter->WriteObjectEnd();
	/* close */
	JsonWriter->Close();

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, SignupInfo);

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	HttpRequest->SetVerb("POST");

	HttpRequest->SetHeader("Content-Type", "application/json;charset=utf-8");

	HttpRequest->SetURL("http://127.0.0.1:7900/user/register-user");

	HttpRequest->SetContentAsString(SignupInfo);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &USignupUserWidget::RequestComplete);

	HttpRequest->ProcessRequest();

}

void USignupUserWidget::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{

	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);

	SignupBtn->SetIsEnabled(true);

	if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{

		return;
	}

	FString Data = ResponsePtr->GetContentAsString();

	TSharedPtr<FJsonObject> JsonObject;

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);

	bool bIsParse = FJsonSerializer::Deserialize(JsonReader, JsonObject);

	if (bIsParse)
	{
		FString Status = JsonObject->GetStringField("status");
		FString Msg = JsonObject->GetStringField("msg");


		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Status);
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Msg);
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MessageBlock->SetText(FText::FromString("Register success!"));
		return;
	}
}
