// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "CoreMinimal.h"
#include "PaperChar_BASE.h"
#include "Protagonist.generated.h"

/**
 * 
 */
UCLASS()
class THETRANSVESTIGATOR_API AProtagonist : public APaperChar_BASE
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	// called for movement input
	void Move(const FInputActionValue& InputValue);

	// Mapping Context for Player Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* ProtagonistMappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	const UInputAction* MovementInputAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	const UInputAction* JumpInputAction = nullptr;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
