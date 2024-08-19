// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinishTrigger.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API AFinishTrigger : public AActor
{
	GENERATED_BODY()
	
public:
	AFinishTrigger();

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Trigger;
	
};
