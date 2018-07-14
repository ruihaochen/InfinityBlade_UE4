// Fill out your copyright notice in the Description page of Project Settings.

#include "XPlayerController.h"
#include "Runtime/Engine/Classes//Kismet//GameplayStatics.h"




void AXPlayerController::BeginPlay()
{
	bShowMouseCursor = true;

	XCharacter = Cast<AXCharacter>(GetPawn());

	/* Init Character state*/
	XPlayerState = Cast<AXPlayerState>(this->PlayerState);

	InitState();

	

	/* Init Animation Instance*/
	XAnimInstance = Cast<UXAnimInstance>(XCharacter->GetMesh()->GetAnimInstance());


	MainWidget = CreateWidget<UMainUserWidget>(GetGameInstance(), LoadClass<UMainUserWidget>(nullptr, TEXT("/Game/UI/BP_MainUserWidget.BP_MainUserWidget_C")));
	
	UpdateUI();

	MainWidget->AddToViewport();


	/* generate a weapon instance*/
	XWeapon = GetWorld()->SpawnActor<AWeapon>(XCharacter->XWeaponClass);
	/* bind rule*/
	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, true);

	/* bind weapon*/
	XWeapon->AttachToComponent(XCharacter->GetMesh(), AttachmentRules, TEXT("hand_rSocket"));
	/* Bind weapon overlap event*/
	XWeapon->CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AXPlayerController::WeaponOverlapDamage);


	InitWidgetEvent();

}

void AXPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	/* Bind input events*/
	InputComponent->BindAxis("MoveForward", this, &AXPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AXPlayerController::MoveRight);
}

void AXPlayerController::MoveForward(float Speed)
{
	FVector fwd = XCharacter->GetActorForwardVector();
	XCharacter->AddMovementInput(fwd, Speed);


	///* get controller rotation*/
	//FRotator Rotation = GetControlRotation();
	///* get yaw*/
	//FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	///* get the move direction*/
	//FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	///* move character*/
	//XCharacter->AddMovementInput(Direction, Speed);


}

void AXPlayerController::MoveRight(float Speed)
{
	
	FVector right = XCharacter->GetActorRightVector();
	XCharacter->AddMovementInput(right, Speed);
	

	///* get controller rotation*/
	//FRotator Rotation = GetControlRotation();
	///* get yaw*/
	//FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	///* get the move direction*/
	//FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	///* move character*/
	//XCharacter->AddMovementInput(Direction, Speed);
}

void AXPlayerController::InitState()
{
	XPlayerState->SetCurrentHP(XCharacter->TotalHP);

	XPlayerState->SetCurrentMP(XCharacter->TotalMP);

	XPlayerState->SetAttackDamage(XCharacter->NormalAttack);
}

void AXPlayerController::UpdateUI()
{
	if (MainWidget->ProgressBar_HP)
	{
		MainWidget->ProgressBar_HP->SetPercent(1.0 - (XPlayerState->GetCurrentHP() / XCharacter->TotalHP));
	}

	if (MainWidget->ProgressBar_MP)
	{
		MainWidget->ProgressBar_MP->SetPercent(1.0 - (XPlayerState->GetCurrentMP() / XCharacter->TotalMP));
	}
}

void AXPlayerController::WeaponOverlapDamage(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool FromSweep, const FHitResult& HitResult)
{
	
	if (XAnimInstance->bIsAttacking)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, "Overlap");
		UGameplayStatics::ApplyDamage(OtherActor, XPlayerState->GetAttackDamage(), this, XCharacter, nullptr);
	}
}

void AXPlayerController::LockAI()
{

}

void AXPlayerController::InitWidgetEvent()
{

	if (MainWidget->BtnAttack)
	{
		MainWidget->BtnAttack->OnClicked.AddDynamic(this, &AXPlayerController::AttackBtnOnClickedEvent);
	}
}

void AXPlayerController::AttackBtnOnClickedEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Attack Event");

	/* Check*/
	if (!XAnimInstance)
	{
		return;
	}
	if (XAnimInstance->bIsPlaying)
	{
		return;
	}
	/* Get SerialAttack Montage*/
	UAnimMontage* SerialAttackMontage = XCharacter->SerialAttackMontage;

	FName CurrentSection = XAnimInstance->Montage_GetCurrentSection(SerialAttackMontage);

	if (CurrentSection.IsNone())
	{
		XAnimInstance->Montage_Play(SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FirstAttack"))
		&& XAnimInstance->bIsEnableSecondAttack)
	{
		/* Play Second Attack*/
		XAnimInstance->Montage_JumpToSection(FName("SecondAttack"),SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("SecondAttack"))
		&& XAnimInstance->bIsEnableThirdAttack)
	{
		/* Play Second Attack*/
		XAnimInstance->Montage_JumpToSection(FName("ThirdAttack"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("ThirdAttack"))
		&& XAnimInstance->bIsEnableFourthAttack)
	{
		/* Play Second Attack*/
		XAnimInstance->Montage_JumpToSection(FName("FourthAttack"), SerialAttackMontage);
	}
	else if (CurrentSection.IsEqual(FName("FourthAttack"))
		&& XAnimInstance->bIsEnableFifthAttack)
	{
		/* Play Second Attack*/
		XAnimInstance->Montage_JumpToSection(FName("FifthAttack"), SerialAttackMontage);
	}
}
