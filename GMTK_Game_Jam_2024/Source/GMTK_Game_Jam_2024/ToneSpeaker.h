// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToneSpeaker.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API AToneSpeaker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToneSpeaker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USoundBase* MiddleC;

	UFUNCTION()
	void F4NotePlayed();

	UFUNCTION()
	void G4NotePlayed();

	UFUNCTION()
	void A4NotePlayed();

	UFUNCTION()
	void C4NotePlayed();

	UFUNCTION()
	void D4NotePlayed();

};
