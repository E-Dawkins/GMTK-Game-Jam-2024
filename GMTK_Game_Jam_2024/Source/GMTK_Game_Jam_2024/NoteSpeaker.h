// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NoteSpeaker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GMTK_GAME_JAM_2024_API UNoteSpeaker : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNoteSpeaker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	USoundBase* FNote;

	UPROPERTY(EditAnywhere)
	USoundBase* GNote;

	UPROPERTY(EditAnywhere)
	USoundBase* ANote;

	UPROPERTY(EditAnywhere)
	USoundBase* CNote;

	UPROPERTY(EditAnywhere)
	USoundBase* DNote;

	void PlayNote(USoundBase* NoteCue);

	UFUNCTION()		  
	void FNotePlayed();
					  
	UFUNCTION()		  
	void GNotePlayed();
					  
	UFUNCTION()		  
	void ANotePlayed();
					  
	UFUNCTION()		  
	void CNotePlayed();
					  
	UFUNCTION()		  
	void DNotePlayed();
};
