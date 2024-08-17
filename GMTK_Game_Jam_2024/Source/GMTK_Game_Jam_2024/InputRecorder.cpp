// Fill out your copyright notice in the Description page of Project Settings.


#include "InputRecorder.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/InputSettings.h"

// Sets default values for this component's properties
UInputRecorder::UInputRecorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UInputRecorder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	StoreMappedKeys();
}


// Called every frame
void UInputRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	int PressedKeysNum = PressedKeys.Num();

	for (FKey Key : MappedKeys)
	{
		if (APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0))
		{
			if (Controller->IsInputKeyDown(Key))
			{
				OnAnyKey(Key, EInputEvent::IE_Pressed);
			}
		}
	}

	if (PressedKeys.Num() != PressedKeysNum)
	{
		for (FKey Key : PressedKeys)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, *Key.ToString());
			}
		}
	}
}

void UInputRecorder::StoreMappedKeys()
{
	UInputSettings* InputSettings = UInputSettings::GetInputSettings();
	UPlayerInput* PlayerInput = UGameplayStatics::GetPlayerController(this, 0)->PlayerInput;

	if (!InputSettings || !PlayerInput)
	{
		return;
	}

	TArray<FName> ActionNames;

	InputSettings->GetActionNames(ActionNames);

	for (FName Name : ActionNames)
	{
		for (FInputActionKeyMapping KeyMap : PlayerInput->GetKeysForAction(Name))
		{
			MappedKeys.Add(KeyMap.Key);
		}
	}


}

void UInputRecorder::OnAnyKey(FKey Key, EInputEvent KeyEvent)
{
	if (PressedKeys.Num() == KeyRecordLimit)
	{
		PressedKeys.RemoveAt(0);
	}

	if (PressedKeys.IsEmpty() || Key != PressedKeys.Last())
	{
		PressedKeys.Add(Key);
	}
}

