// Fill out your copyright notice in the Description page of Project Settings.

#include "MainUserWidget.h"




bool UMainUserWidget::Initialize()
{
	if (!Super::Initialize())
		return false;


	BtnAttack = Cast<UButton>(GetWidgetFromName(TEXT("Button_Attack")));

	//ProgressBar_HP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_HP")));

	//ProgressBar_MP = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar_MP")));

	return true;
}
