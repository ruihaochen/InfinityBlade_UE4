// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));


	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));

	WeaponComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponComponent"));

	WeaponComponent->SetupAttachment(RootComponent);

	CapsuleComponent->SetupAttachment(WeaponComponent);
}

