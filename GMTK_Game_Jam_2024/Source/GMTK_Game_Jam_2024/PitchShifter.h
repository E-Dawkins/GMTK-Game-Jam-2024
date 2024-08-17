// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PitchShifter.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API APitchShifter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APitchShifter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USoundBase* MiddleC;

	UPROPERTY(EditAnywhere)
	float Pitch;
};
