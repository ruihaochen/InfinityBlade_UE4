// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"

bool UStartUserWidget::Initialize()
{

	if (!Super::Initialize())
	{
		return false;
	}

	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));

	SignUpBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_SignUp")));

	ExitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Exit")));
	/* Exit Button On Click Event*/
	ExitBtn->OnClicked.AddDynamic(this, &UStartUserWidget::ExitBtnOnClickedEvent);
	
	return true;
}

void UStartUserWidget::ExitBtnOnClickedEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("ExitGame"));
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit);
}
