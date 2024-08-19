// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteSpeaker.h"
#include "ToneManagerSubsystem.h"
#include <Kismet/GameplayStatics.h>


// Sets default values for this component's properties
UNoteSpeaker::UNoteSpeaker()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNoteSpeaker::BeginPlay()
{
	Super::BeginPlay();


	if (UToneManagerSubsystem* ToneManager = GetWorld()->GetSubsystem<UToneManagerSubsystem>())
	{
		ToneManager->OnFNotePlayed.AddDynamic(this, &UNoteSpeaker::FNotePlayed);
		ToneManager->OnGNotePlayed.AddDynamic(this, &UNoteSpeaker::GNotePlayed);
		ToneManager->OnANotePlayed.AddDynamic(this, &UNoteSpeaker::ANotePlayed);
		ToneManager->OnCNotePlayed.AddDynamic(this, &UNoteSpeaker::CNotePlayed);
		ToneManager->OnDNotePlayed.AddDynamic(this, &UNoteSpeaker::DNotePlayed);

	}
	
}

void UNoteSpeaker::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNoteSpeaker::PlayNote(USoundBase* NoteCue)
{ 
	if (NoteCue) UGameplayStatics::PlaySound2D(this, NoteCue);
}

void UNoteSpeaker::FNotePlayed() {PlayNote(FNote); }
void UNoteSpeaker::GNotePlayed() {PlayNote(GNote); }
void UNoteSpeaker::ANotePlayed() {PlayNote(ANote); }
void UNoteSpeaker::CNotePlayed() {PlayNote(CNote); }
void UNoteSpeaker::DNotePlayed() {PlayNote(DNote); }

