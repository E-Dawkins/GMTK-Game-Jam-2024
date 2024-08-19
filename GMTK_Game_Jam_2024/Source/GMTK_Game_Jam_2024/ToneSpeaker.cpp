// Fill out your copyright notice in the Description page of Project Settings.


#include "ToneSpeaker.h"
#include "ToneManagerSubsystem.h"
#include <Kismet/GameplayStatics.h>


// Sets default values
AToneSpeaker::AToneSpeaker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AToneSpeaker::BeginPlay()
{
	Super::BeginPlay();
	
	if (UToneManagerSubsystem* ToneManager = GetWorld()->GetSubsystem<UToneManagerSubsystem>())
	{
		ToneManager->OnFNotePlayed.AddDynamic(this, &AToneSpeaker::F4NotePlayed);
		ToneManager->OnGNotePlayed.AddDynamic(this, &AToneSpeaker::G4NotePlayed);
		ToneManager->OnANotePlayed.AddDynamic(this, &AToneSpeaker::A4NotePlayed);
		ToneManager->OnCNotePlayed.AddDynamic(this, &AToneSpeaker::C4NotePlayed);
		ToneManager->OnDNotePlayed.AddDynamic(this, &AToneSpeaker::D4NotePlayed);

	}

}

// Called every frame
void AToneSpeaker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AToneSpeaker::F4NotePlayed()
{
	if (MiddleC)
	{
		UGameplayStatics::PlaySound2D(this, MiddleC, 1, 1.233f);
	}
}

void AToneSpeaker::G4NotePlayed()
{
	if (MiddleC)
	{
		UGameplayStatics::PlaySound2D(this, MiddleC, 1, 1.333f);
	}
}

void AToneSpeaker::A4NotePlayed()
{
	if (MiddleC)
	{
		UGameplayStatics::PlaySound2D(this, MiddleC, 1, 1.40f);
	}
}

void AToneSpeaker::C4NotePlayed()
{
	if (MiddleC)
	{
		UGameplayStatics::PlaySound2D(this, MiddleC, 1, 1.f);

	}
}

void AToneSpeaker::D4NotePlayed()
{
	if (MiddleC)
	{
		UGameplayStatics::PlaySound2D(this, MiddleC, 1, 1.11f);
	}
}

