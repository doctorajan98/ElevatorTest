// Copyright Epic Games, Inc. All Rights Reserved.

#include "ElevatorTestGameMode.h"
#include "ElevatorTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AElevatorTestGameMode::AElevatorTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
