// Fill out your copyright notice in the Description page of Project Settings.

#include "LoginUserWidget.h"




bool ULoginUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));

	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));

	LoginBtn->OnClicked.AddDynamic(this, &ULoginUserWidget::LoginBtnOnClickedEvent);
	
	UsernameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TextBox_Username")));

	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TextBox_Password")));


	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Loading")));

	MessageWidget = Cast<UMessageUserWidget>(GetWidgetFromName(TEXT("BP_MessageUserWidget")));

	return true;
}

void ULoginUserWidget::LoginBtnOnClickedEvent()
{
	

	FString Username = UsernameInput->GetText().ToString();

	FString Password = PasswordInput->GetText().ToString();

	if (Username.IsEmpty())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "username is empty");
		MessageWidget->MessageBlock->SetText(FText::FromString("Username is empty!"));

		MessageWidget->SetVisibility(ESlateVisibility::Visible);
		return;
	}

	if (Password.IsEmpty())
	{
		MessageWidget->MessageBlock->SetText(FText::FromString("Password is empty!"));

		MessageWidget->SetVisibility(ESlateVisibility::Visible);
		return;
	}

	CircularThrobber->SetVisibility(ESlateVisibility::Visible);

	LoginBtn->SetIsEnabled(false);

	AccoutnLoginFromServer(Username, Password);
}

void ULoginUserWidget::AccoutnLoginFromServer(FString Username, FString Password)
{
	FString LoginInfo;
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&LoginInfo);
	/* start input data into json writer*/
	JsonWriter->WriteObjectStart();

	JsonWriter->WriteValue("nickname", Username);

	JsonWriter->WriteValue("password", Password);

	JsonWriter->WriteObjectEnd();
	/* close */
	JsonWriter->Close();

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, LoginInfo);

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	HttpRequest->SetVerb("POST");

	HttpRequest->SetHeader("Content-Type", "application/json;charset=utf-8");

	HttpRequest->SetURL("http://127.0.0.1:7900/user/login-user");

	HttpRequest->SetContentAsString(LoginInfo);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &ULoginUserWidget::RequestComplete);

	HttpRequest->ProcessRequest();
}

void ULoginUserWidget::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{

	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);

	LoginBtn->SetIsEnabled(true);

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
		FString Msg = JsonObject->GetStringField("Msg");
		TSharedPtr<FJsonObject> JsonData = JsonObject->GetObjectField("data");
		FString id = JsonData->GetStringField("id");
		FString Username = JsonData->GetStringField("nickname");
		if (!Username.IsEmpty())
		{
			/* Loading level*/
			UCustomGameInstance* GameInstance = Cast<UCustomGameInstance>(GetWorld()->GetGameInstance());

			GameInstance->ContextMap.Add("id", id);
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Map/Map_Main.Map_Main"));
		}
		else
		{
			MessageWidget->MessageBlock->SetText(FText::FromString("Username or Password is wrong!"));

			MessageWidget->SetVisibility(ESlateVisibility::Visible);
		}


		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, id);
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Msg);
		return;
	}
}
