// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UENUM()
enum ENotes
{
	ENotes_F UMETA(DisplayName = "F"),
	ENotes_G UMETA(DisplayName = "G"),
	ENotes_A UMETA(DisplayName = "A"),
	ENotes_C UMETA(DisplayName = "C"),
	ENotes_D UMETA(DisplayName = "D"),
};

UCLASS()
class GMTK_GAME_JAM_2024_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:
	AObstacle();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	virtual void Activate();

	UFUNCTION()
	virtual void DeActivate();

protected:
	template<typename DelegateType = TBaseDynamicMulticastDelegate<FWeakObjectPtr, void>>
	void BindNoteDelegate(DelegateType& NoteDelegate, bool bBindToActivate);

protected:
	UPROPERTY(EditAnywhere)
	TEnumAsByte<ENotes> ActivationNote = ENotes_F;
	
protected:
	bool bActivated = false;

};

template <typename DelegateType>
void AObstacle::BindNoteDelegate(DelegateType& NoteDelegate, bool bBindToActivate)
{
	if (bBindToActivate)
	{
		NoteDelegate.AddDynamic(this, &AObstacle::Activate);
	}
	else
	{
		NoteDelegate.AddDynamic(this, &AObstacle::DeActivate);
	}
}
