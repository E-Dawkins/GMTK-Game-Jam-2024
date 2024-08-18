// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:
	AObstacle();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	virtual void Activate();

	UFUNCTION()
	virtual void DeActivate();

protected:
	bool bActivated = false;

};
