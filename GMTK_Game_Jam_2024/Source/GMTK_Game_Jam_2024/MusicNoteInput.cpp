// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicNoteInput.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AMusicNoteInput::AMusicNoteInput()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("Root Mesh");
	SetRootComponent(RootMesh);

	Trigger = CreateDefaultSubobject<UStaticMeshComponent>("Trigger");
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetCollisionProfileName("OverlapAllDynamic");
}

void AMusicNoteInput::BeginPlay()
{
	Super::BeginPlay();

	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMusicNoteInput::BeginComponentOverlap);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AMusicNoteInput::EndComponentOverlap);

	PCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	PController = Cast<APlayerController>(PCharacter->GetController());

	NoteInputPtr = CreateWidget(GetWorld(), NoteInputClass);
}

void AMusicNoteInput::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bPlayerInTrigger)
	{
		if (PController->WasInputKeyJustPressed(EKeys::E)) // yes, this is hardcoded (eww)
		{
			OnInteract();
		}
	}
}

void AMusicNoteInput::BeginComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor == PCharacter)
	{
		bPlayerInTrigger = true;
	}
}

void AMusicNoteInput::EndComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor == PCharacter)
	{
		bPlayerInTrigger = false;
	}
}

void AMusicNoteInput::OnInteract()
{
	NoteInputPtr->AddToViewport();
        
	PController->SetInputMode(FInputModeUIOnly());
	PController->SetShowMouseCursor(true);
}
