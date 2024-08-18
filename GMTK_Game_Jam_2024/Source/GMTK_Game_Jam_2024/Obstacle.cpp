// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
	
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	// Bind functions here
}

void AObstacle::Activate()
{
	bActivated = true;
}

void AObstacle::DeActivate()
{
	bActivated = false;
}

