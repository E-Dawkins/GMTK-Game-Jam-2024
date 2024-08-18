// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "GameFramework/Actor.h"
#include "MusicNoteInput.generated.h"

UCLASS()
class GMTK_GAME_JAM_2024_API AMusicNoteInput : public AActor
{
	GENERATED_BODY()
	
public:	
	AMusicNoteInput();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	
	UFUNCTION()
	void BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	void OnInteract();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* RootMesh;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Trigger;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> NoteInputClass;

	UPROPERTY()
	UUserWidget* NoteInputPtr = nullptr;

	UPROPERTY()
	APlayerCharacter* PCharacter;

	UPROPERTY()
	APlayerController* PController;

	bool bPlayerInTrigger;

};
