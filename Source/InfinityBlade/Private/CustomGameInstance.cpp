// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameInstance.h"




void UCustomGameInstance::Init()
{
	UGameInstance::Init();

	/* Start load map delegation*/
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UCustomGameInstance::PreLoadMap);
	/* End load map delegation*/
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UCustomGameInstance::PostLoadMap);

	LoadUserWidget = CreateWidget<ULoadUserWidget>(this, LoadClass<ULoadUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_LoadUserWidget.BP_LoadUserWidget_C'")));


}

void UCustomGameInstance::PreLoadMap(const FString & Map)
{
	
	LoadUserWidget->AddToViewport();
	if (!Map.Equals("/Game/Map/Map_Main.Map_Main"))
	{
		return;
	}
	FLoadingScreenAttributes LoadingAttr;
	LoadingAttr.WidgetLoadingScreen = LoadUserWidget->TakeWidget();
	LoadingAttr.bAutoCompleteWhenLoadingCompletes = false;
	LoadingAttr.bWaitForManualStop = true;
	GetMoviePlayer()->SetupLoadingScreen(LoadingAttr);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Preload...");
}

void UCustomGameInstance::PostLoadMap(UWorld * World)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, "Postload...");

	/*LoadUserWidget->CircularThrobber->SetVisibility(ESlateVisibility::Hidden);

	LoadUserWidget->LoadingText->SetVisibility(ESlateVisibility::Hidden);

	LoadUserWidget->ContinueText->SetVisibility(ESlateVisibility::Visible);*/

}

bool UCustomGameInstance::GetLoadStatus()
{
	return GetMoviePlayer()->IsLoadingFinished();
}
