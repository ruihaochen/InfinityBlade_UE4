// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "Components/ProgressBar.h"

#include "AICharacter.generated.h"

UCLASS()
class INFINITYBLADE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()


public:

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* WidgetComponent;
	UPROPERTY(EditAnywhere, Category = "State")
		float TotalHP;

	float CurrentHP;
	UPROPERTY()
		UProgressBar* HPBar;
public:
	// Sets default values for this character's properties
	AAICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	
};
