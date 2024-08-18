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
	
	Activate();
	
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, this, &AObsPlatform::DeActivate, 3.f);
}

void AObsPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CurAnimTime = FMath::Clamp(CurAnimTime + DeltaSeconds, 0, AnimTime);

	Mesh->SetRelativeLocation(TargetOffset * FMath::Abs((!bActivated) - (CurAnimTime / AnimTime)));
}

void AObsPlatform::Activate()
{
	Super::Activate();

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Platform Activate");
	UpdateAnim();
}

void AObsPlatform::DeActivate()
{
	Super::DeActivate();

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, "Platform DeActivate");
	UpdateAnim();
}

void AObsPlatform::UpdateAnim()
{
	FVector Target = (bActivated ? TargetOffset : FVector::ZeroVector);

	float Dist = FVector::Dist(Mesh->GetRelativeLocation(), Target);

	float Percentage = 1.f - (Dist / TargetOffset.Length());
	
	CurAnimTime = AnimTime * Percentage;
}
