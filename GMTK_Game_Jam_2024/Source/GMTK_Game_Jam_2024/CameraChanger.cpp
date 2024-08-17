// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraChanger.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraChanger::ACameraChanger()
{
	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("Root Mesh");
	SetRootComponent(RootMesh);
	
	Trigger = CreateDefaultSubobject<UStaticMeshComponent>("Trigger Box");
	Trigger->SetupAttachment(RootComponent);

	bPlayerInTrigger = false;
}

// Called when the game starts or when spawned
void ACameraChanger::BeginPlay()
{
	Super::BeginPlay();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ACameraChanger::BeginComponentOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &ACameraChanger::EndComponentOverlap);

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		EnableInput(PlayerController);
		InputComponent->BindAction("Interact", IE_Pressed, this, &ACameraChanger::OnInteract);
	}

	PCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	PController = Cast<APlayerController>(PCharacter->GetController());
}

void ACameraChanger::BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor == PCharacter)
	{
		bPlayerInTrigger = true;
	}
}

void ACameraChanger::EndComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor == PCharacter)
	{
		bPlayerInTrigger = false;
		SetViewTarget(true); // failsafe
	}
}

void ACameraChanger::OnInteract()
{
	if (bPlayerInTrigger)
	{
		SetViewTarget(PController->GetViewTarget() != PCharacter);
	}
}

void ACameraChanger::SetViewTarget(const bool bTargetPlayer) const
{
	if (bTargetPlayer)
	{
		PController->SetViewTarget(PCharacter);
	}
	else
	{
		PController->SetViewTarget(NewViewTarget);
	}
}

