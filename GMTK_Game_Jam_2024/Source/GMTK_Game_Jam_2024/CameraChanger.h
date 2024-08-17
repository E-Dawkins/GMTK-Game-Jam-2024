// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "GameFramework/Actor.h"
#include "CameraChanger.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API ACameraChanger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraChanger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	void OnInteract();

	void SetViewTarget(bool bTargetPlayer) const;
	
protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* RootMesh;
	
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Trigger;

	UPROPERTY(EditAnywhere)
	AActor* NewViewTarget;
	
	bool bPlayerInTrigger;

	UPROPERTY()
	APlayerCharacter* PCharacter;

	UPROPERTY()
	APlayerController* PController;

};
