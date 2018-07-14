// Fill out your copyright notice in the Description page of Project Settings.

#include "MessageUserWidget.h"

bool UMessageUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;


	CloseBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Close")));

	MessageBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Message")));

	CloseBtn->OnClicked.AddDynamic(this, &UMessageUserWidget::CloseBtnOnClickedEvent);

	return true;
}

void UMessageUserWidget::CloseBtnOnClickedEvent()
{

	this->SetVisibility(ESlateVisibility::Hidden);
}
