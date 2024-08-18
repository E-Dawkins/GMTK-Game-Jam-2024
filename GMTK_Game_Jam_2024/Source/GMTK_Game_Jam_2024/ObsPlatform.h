// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "ObsPlatform.generated.h"

/**
 * 
 */
UCLASS()
class GMTK_GAME_JAM_2024_API AObsPlatform : public AObstacle
{
	GENERATED_BODY()

	AObsPlatform();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void Activate() override;
	virtual void DeActivate() override;

protected:
	void UpdateAnim();

protected:
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* DefaultRoot;
	
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere)
	FVector TargetOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float AnimTime = 1.5f;

	UPROPERTY(VisibleAnywhere)
	float CurAnimTime = 0.f;
	
};
