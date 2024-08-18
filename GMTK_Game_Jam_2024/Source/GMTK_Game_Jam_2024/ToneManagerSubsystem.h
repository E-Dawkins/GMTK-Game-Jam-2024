// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ToneManagerSubsystem.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_EXTERN(ToneManagerSubsystem,Log,All)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFNotePlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGNotePlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnANotePlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCNotePlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDNotePlayed);


UCLASS()
class GMTK_GAME_JAM_2024_API UToneManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable)
	FOnFNotePlayed OnFNotePlayed;

	UPROPERTY(BlueprintAssignable)
	FOnFNotePlayed OnGNotePlayed;

	UPROPERTY(BlueprintAssignable)
	FOnFNotePlayed OnANotePlayed;

	UPROPERTY(BlueprintAssignable)
	FOnFNotePlayed OnCNotePlayed;

	UPROPERTY(BlueprintAssignable)
	FOnFNotePlayed OnDNotePlayed;


	void PlayFTone();
	void PlayGTone();
	void PlayATone();
	void PlayCTone();
	void PlayDTone();
};
