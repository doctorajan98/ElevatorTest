// Fill out your copyright notice in the Description page of Project Settings.


#include "ElevatorTest/Public/World/Elevator/ET_ElevatorTrigger.h"
#include "World/Elevator/ET_ElevatorTrigger.h"
#include "Components/BrushComponent.h"
#include "ElevatorTest/ElevatorTestPlayerController.h"
#include "ElevatorTest/Public/Core/GameInstance/ET_GameInstance.h"

class AElevatorTestPlayerController;

AET_ElevatorTrigger::AET_ElevatorTrigger()
{
	UBrushComponent* NewBrushComponent = GetBrushComponent();
	NewBrushComponent->SetCollisionProfileName("OverlapAllDynamic");
	
}

void AET_ElevatorTrigger::BeginPlay()
{
	OnActorBeginOverlap.AddUniqueDynamic(this, &AET_ElevatorTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddUniqueDynamic(this, &AET_ElevatorTrigger::OnOverlapEnd);
}

void AET_ElevatorTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		PlayerCharacter = Cast<AElevatorTestCharacter>(OtherActor);
		if (!PlayerCharacter) return;
		
		AElevatorTestPlayerController* PC = Cast<AElevatorTestPlayerController>(PlayerCharacter->GetController());
		if (!PC)
		{
			UE_LOG(LogTemp, Warning, TEXT("AET_ElevatorTrigger: PlayerController not valid"));
			return;
		}

		// Make cursor Game and UI
		PC->SetInputMode(FInputModeGameAndUI());

		// Set Current trigger to be current floor
		if (UET_GameInstance* GI = GetGameInstance<UET_GameInstance>())
		{
			GI->SetCurrentFloor(CurrentLevel);
		}
		
		if (UET_ElevatorWidget* ElevatorUI = Cast<UET_ElevatorWidget>(PC->GetElevatorUI()))
		{
			// Check Elevator Enum
			switch (ElevatorType)
			{
			case request_floor:
				// Show request_floor UI
					ElevatorUI->RequestFloorUI(true);
				break;

			case call_Elevator:
				// Show call_Elevator UI
					ElevatorUI->CallElevatorUI(true);
				break;

			default:
				break;
			}
		}
	}
}

void AET_ElevatorTrigger::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		// Make cursor Game only
		if (!PlayerCharacter) return;
		
		AElevatorTestPlayerController* PC = Cast<AElevatorTestPlayerController>(PlayerCharacter->GetController());
		if (!PC)
		{
			UE_LOG(LogTemp, Warning, TEXT("AET_ElevatorTrigger: PlayerController not valid"));
			return;
		}
		PC->SetInputMode(FInputModeGameOnly());
		
		PlayerCharacter = nullptr;
		
	}
}
