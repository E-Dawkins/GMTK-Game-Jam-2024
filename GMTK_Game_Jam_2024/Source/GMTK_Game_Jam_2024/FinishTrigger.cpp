// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishTrigger.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AFinishTrigger::AFinishTrigger()
{
	Trigger = CreateDefaultSubobject<UStaticMeshComponent>("Trigger");
	SetRootComponent(Trigger);
	Trigger->SetCollisionProfileName("OverlapAllDynamic");

}

void AFinishTrigger::BeginPlay()
{
	Super::BeginPlay();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFinishTrigger::BeginComponentOverlap);
}

void AFinishTrigger::BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor == UGameplayStatics::GetPlayerCharacter(this, 0))
	{
		UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
	}
}
