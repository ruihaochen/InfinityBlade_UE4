// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"




void AStartGameMode::BeginPlay()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Start Game Mode"));

	/* Initialize Start Widget*/

	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this,TEXT("WidgetBlueprint'/Game/UI/BP_StartUserWidget.BP_StartUserWidget_C'")));

	StartWidget->AddToViewport();

	StartWidget->SignUpBtn->OnClicked.AddDynamic(this, &AStartGameMode::SignupBtnOnClickedEvent);
	
	StartWidget->StartBtn->OnClicked.AddDynamic(this, &AStartGameMode::StartBtnOnClickedEvent);
	
	
	/* Signup Widget Button event*/
	SignupWidget = CreateWidget<USignupUserWidget>(GetGameInstance(), LoadClass<USignupUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_SignupUserWidget.BP_SignupUserWidget_C'")));

	SignupWidget->BackBtn->OnClicked.AddDynamic(this, &AStartGameMode::SignupBackBtnOnClickedEvent);

	
	/* Login widget button event*/
	LoginWidget = CreateWidget<ULoginUserWidget>(GetGameInstance(), LoadClass<ULoginUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_LoginUserWidget.BP_LoginUserWidget_C'")));

	LoginWidget->BackBtn->OnClicked.AddDynamic(this, &AStartGameMode::LoginBackBtnOnClickedEvent);

}

void AStartGameMode::SignupBtnOnClickedEvent()
{

	StartWidget->RemoveFromViewport();
	SignupWidget->AddToViewport();
}

void AStartGameMode::StartBtnOnClickedEvent()
{
	StartWidget->RemoveFromViewport();
	LoginWidget->AddToViewport();
}


void AStartGameMode::SignupBackBtnOnClickedEvent()
{
	SignupWidget->RemoveFromViewport();
	StartWidget->AddToViewport();
}

void AStartGameMode::LoginBackBtnOnClickedEvent()
{
	LoginWidget->RemoveFromViewport();
	StartWidget->AddToViewport();
}
