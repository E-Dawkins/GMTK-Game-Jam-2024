// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MusicStaveWidget.generated.h"

/**
 * 
 */
UCLASS()
class GMTK_GAME_JAM_2024_API UMusicStaveWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	// Doing setup in the C++ constructor is not as
	// useful as using NativeConstruct.
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "PlayScale")
	void PlayFMajorPentatonicScale();

	UPROPERTY(BlueprintReadWrite)
	TArray<UWidget*> NoteSliderWidgets;

	UPROPERTY(EditAnywhere)
	float TimeBetweenNotes = 2.f;
};
