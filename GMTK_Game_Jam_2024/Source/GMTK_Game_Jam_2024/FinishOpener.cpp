// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishOpener.h"

AFinishOpener::AFinishOpener()
{
	Trigger = CreateDefaultSubobject<UStaticMeshComponent>("Trigger");
	SetRootComponent(Trigger);
	Trigger->SetCollisionProfileName("OverlapAllDynamic");
}

void AFinishOpener::BeginPlay()
{
	Super::BeginPlay();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFinishOpener::BeginComponentOverlap);
}

void AFinishOpener::BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(ActorToDelete))
	{
		ActorToDelete->Destroy();
	}
}

