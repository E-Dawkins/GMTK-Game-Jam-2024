// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "ToneManagerSubsystem.h"

// Sets default values
AObstacle::AObstacle()
{
	
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	// Bind functions here
	if (auto ToneManager = GetWorld()->GetSubsystem<UToneManagerSubsystem>())
	{
		BindNoteDelegate(ToneManager->OnFNotePlayed, (ActivationNote == ENotes_F));
		BindNoteDelegate(ToneManager->OnGNotePlayed, (ActivationNote == ENotes_G));
		BindNoteDelegate(ToneManager->OnANotePlayed, (ActivationNote == ENotes_A));
		BindNoteDelegate(ToneManager->OnCNotePlayed, (ActivationNote == ENotes_C));
		BindNoteDelegate(ToneManager->OnDNotePlayed, (ActivationNote == ENotes_D));
		BindNoteDelegate(ToneManager->OnEndOfNotes, false);
	}

}

void AObstacle::Activate()
{
	bActivated = true;
}

void AObstacle::DeActivate()
{
	bActivated = false;
}
