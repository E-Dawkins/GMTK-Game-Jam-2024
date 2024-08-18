// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicStaveWidget.h"
#include "Components/Slider.h"
#include "ToneManagerSubsystem.h"

void UMusicStaveWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Warning, TEXT("Construct"))
}

void UMusicStaveWidget::PlayFMajorPentatonicScale()
{
	if (UToneManagerSubsystem* ToneManager = GetWorld()->GetSubsystem<UToneManagerSubsystem>())
	{
		for (UWidget* SliderWidget : NoteSliderWidgets)
		{
			USlider* Slider = (USlider*)SliderWidget;

			if (Slider)
			{
				switch (int NoteValue = Slider->Value)
				{
				case 1:
					ToneManager->PlayFTone();
						break;
				case 2:
					ToneManager->PlayGTone();
						break;
				case 3:
					ToneManager->PlayATone();
						break;
				case 4:
					ToneManager->PlayCTone();
						break;
				case 5:
					ToneManager->PlayDTone();
						break;
				default:
					UE_LOG(LogTemp, Warning, TEXT("MusicStaveWidget : No Note Selected"))
						break;
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Slider not found"))
			}

		}
	}
}
