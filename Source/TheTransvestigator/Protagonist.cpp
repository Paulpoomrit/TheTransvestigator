// Fill out your copyright notice in the Description page of Project Settings.


#include "Protagonist.h"

void AProtagonist::BeginPlay()
{
	Super::BeginPlay();

	// Add Input Mapping Context
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem && ProtagonistMappingContext)
		{
			Subsystem->AddMappingContext(ProtagonistMappingContext, 0);
		}
	}
}

void AProtagonist::Move(const FInputActionValue& InputValue)
{
	const FVector2d DirectionalValue2d = InputValue.Get<FVector2d>();
	AddMovementInput(FVector(1,0,0), DirectionalValue2d.X);
	AddMovementInput(FVector(0,1,0), DirectionalValue2d.Y);
}

void AProtagonist::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	// set up action bindings
	// CastChecked -> crash game if the cast fail
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MovementInputAction, ETriggerEvent::Triggered, this, &AProtagonist::Move);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &AProtagonist::Jump);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Completed, this, &AProtagonist::StopJumping);
	}
}
