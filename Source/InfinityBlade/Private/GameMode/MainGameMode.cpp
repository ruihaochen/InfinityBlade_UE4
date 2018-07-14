// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"




AMainGameMode::AMainGameMode()
{
	ConstructorHelpers::FClassFinder<AXCharacter> CharacterFinder(TEXT("/Game/Character/BP_XCharacter.BP_XCharacter_C"));

	DefaultPawnClass = CharacterFinder.Class;


	PlayerControllerClass = AXPlayerController::StaticClass();


	PlayerStateClass = AXPlayerState::StaticClass();
}

void AMainGameMode::BeginPlay()
{

}
