// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// protected:
// 	virtual void BeginPlay() override;
//
// public:	
// 	virtual void Tick(float DeltaTime) override;

protected:
	// Axis Mappings -->
	
	void MoveRight(float Value);
	void MoveForward(float Value);
	void MouseRight(float Value);
	void MouseUp(float Value);

	// <-- Axis Mappings
};
