// Fill out your copyright notice in the Description page of Project Settings.


#include "ObsPlatform.h"

AObsPlatform::AObsPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(DefaultRoot);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

void AObsPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	// Activate();
	//
	// FTimerHandle Handle;
	// GetWorld()->GetTimerManager().SetTimer(Handle, this, &AObsPlatform::DeActivate, 3.f);

	UpdateAnim();
}

void AObsPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CurAnimTime = FMath::Clamp(CurAnimTime + (bActivated ? DeltaSeconds : -DeltaSeconds), 0, AnimTime);

	Mesh->SetRelativeLocation(TargetOffset * (CurAnimTime / AnimTime));
}

void AObsPlatform::Activate()
{
	Super::Activate();
	
	UpdateAnim();
}

void AObsPlatform::DeActivate()
{
	Super::DeActivate();
	
	UpdateAnim();
}

void AObsPlatform::UpdateAnim()
{
	FVector Target = (bActivated ? TargetOffset : FVector::ZeroVector);

	float Dist = FVector::Dist(Mesh->GetRelativeLocation(), Target);

	float Percentage = (Dist / TargetOffset.Length());
	Percentage = (bActivated ? 1.f - Percentage : Percentage);

	CurAnimTime = AnimTime * Percentage;
}
