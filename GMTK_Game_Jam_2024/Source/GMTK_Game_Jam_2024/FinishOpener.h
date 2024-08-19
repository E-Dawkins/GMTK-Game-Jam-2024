// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FinishOpener.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API AFinishOpener : public AActor
{
	GENERATED_BODY()
	
public:	
	AFinishOpener();

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Trigger;

	UPROPERTY(EditAnywhere)
	AActor* ActorToDelete;

};
