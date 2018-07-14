// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadUserWidget.h"




bool ULoadUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Loading")));

	LoadingText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Loading")));

	ContinueText= Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Continue")));

	return true;
}
