// Fill out your copyright notice in the Description page of Project Settings.


#include "ToneManagerSubsystem.h"
#include <Kismet/GameplayStatics.h>

DEFINE_LOG_CATEGORY(ToneManagerSubsystem)

void UToneManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::Initialize"))
}

void UToneManagerSubsystem::Deinitialize()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::Deinitialize"))
}

void UToneManagerSubsystem::PlayFTone()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::FTone"));
	OnFNotePlayed.Broadcast();
}

void UToneManagerSubsystem::PlayGTone()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::GTone"));
	OnGNotePlayed.Broadcast();
}

void UToneManagerSubsystem::PlayATone()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::ATone"));
	OnANotePlayed.Broadcast();
}

void UToneManagerSubsystem::PlayCTone()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::CTone"));
	OnCNotePlayed.Broadcast();
}

void UToneManagerSubsystem::PlayDTone()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::DTone"));
	OnDNotePlayed.Broadcast();
}

void UToneManagerSubsystem::PlayEndOfNotes()
{
	UE_LOG_REF(ToneManagerSubsystem, Warning, TEXT("ToneManagerSubsystem::EndOfNotes"));
	OnEndOfNotes.Broadcast();
}
