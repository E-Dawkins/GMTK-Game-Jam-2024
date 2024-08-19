// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Kismet/GameplayStatics.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MouseRight", this, &APlayerCharacter::MouseRight);
	PlayerInputComponent->BindAxis("MouseUp", this, &APlayerCharacter::MouseUp);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("RestartLevel", IE_Pressed, this, &APlayerCharacter::RestartLevel);
	PlayerInputComponent->BindAction("MainMenu", IE_Pressed, this, &APlayerCharacter::MainMenu);
}

void APlayerCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::MouseRight(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::MouseUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::RestartLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), *UGameplayStatics::GetCurrentLevelName(GetWorld()));
}

void APlayerCharacter::MainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}
