// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputRecorder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GMTK_GAME_JAM_2024_API UInputRecorder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputRecorder();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void OnAnyKey(FKey Key, EInputEvent KeyEvent);
	void StoreMappedKeys();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	TArray<FKey> MappedKeys;

	UPROPERTY(EditAnywhere)
	int KeyRecordLimit = 7;

	TArray<FKey> PressedKeys;

};
