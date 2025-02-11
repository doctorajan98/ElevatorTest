// Copyright Epic Games, Inc. All Rights Reserved.


#include "ElevatorTestPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AElevatorTestPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);

		UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	}

	if (IsValid(ElevatorWidgetClass))
	{
		ElevatorWidget = CreateWidget(this, this->ElevatorWidgetClass);
		ElevatorWidget->AddToViewport();
	}
}