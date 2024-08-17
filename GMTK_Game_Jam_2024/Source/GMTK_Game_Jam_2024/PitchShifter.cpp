// Fill out your copyright notice in the Description page of Project Settings.


#include "PitchShifter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APitchShifter::APitchShifter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APitchShifter::BeginPlay()
{
	Super::BeginPlay();
	
	if (MiddleC)
	{
		UGameplayStatics::PlaySound2D(this, MiddleC, 1, Pitch);
	}
}

// Called every frame
void APitchShifter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

