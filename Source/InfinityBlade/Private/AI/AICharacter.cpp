// Fill out your copyright notice in the Description page of Project Settings.

#include "AICharacter.h"


// Sets default values
AAICharacter::AAICharacter()
{
	// init UI component

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));

	WidgetComponent->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	HPBar = Cast<UProgressBar>(WidgetComponent->GetUserWidgetObject()->GetWidgetFromName(TEXT("AIHPBar")));
	CurrentHP = TotalHP;
	HPBar->SetPercent(CurrentHP / TotalHP);

}

float AAICharacter::TakeDamage(float Damage, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{

	CurrentHP -= Damage;
	HPBar->SetPercent(CurrentHP / TotalHP);

	return Damage;
}


