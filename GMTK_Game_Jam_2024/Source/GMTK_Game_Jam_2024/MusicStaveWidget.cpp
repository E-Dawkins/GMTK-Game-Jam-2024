// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicStaveWidget.h"
#include "Components/Slider.h"
#include "ToneManagerSubsystem.h"

void UMusicStaveWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Warning, TEXT("Construct"))

	if (UToneManagerSubsystem* ToneManager = GetWorld()->GetSubsystem<UToneManagerSubsystem>())
	{
		GetWorld()->GetTimerManager().ClearAllTimersForObject(ToneManager);
		ToneManager->PlayEndOfNotes();
	}
}

void UMusicStaveWidget::PlayFMajorPentatonicScale()
{
	if (UToneManagerSubsystem* ToneManager = GetWorld()->GetSubsystem<UToneManagerSubsystem>())
	{
		float TimerStart = 0.f;
		
		for (UWidget* SliderWidget : NoteSliderWidgets)
		{
			FTimerDelegate TimerDelegate;
			TimerStart += TimeBetweenNotes;

			if (auto Slider = Cast<USlider>(SliderWidget))
			{
				switch(int Temp = Slider->GetValue())
				{
					case 1: TimerDelegate.BindUObject(ToneManager, &UToneManagerSubsystem::PlayFTone); break;
					case 2: TimerDelegate.BindUObject(ToneManager, &UToneManagerSubsystem::PlayGTone); break;
					case 3: TimerDelegate.BindUObject(ToneManager, &UToneManagerSubsystem::PlayATone); break;
					case 4: TimerDelegate.BindUObject(ToneManager, &UToneManagerSubsystem::PlayCTone); break;
					case 5: TimerDelegate.BindUObject(ToneManager, &UToneManagerSubsystem::PlayDTone); break;
					default: TimerDelegate.BindUObject(ToneManager, &UToneManagerSubsystem::PlayEndOfNotes); break;
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Slider not found"));
			}

			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, TimerStart, false);
		}

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, ToneManager, &UToneManagerSubsystem::PlayEndOfNotes, TimerStart + TimeBetweenNotes);
	}
}
