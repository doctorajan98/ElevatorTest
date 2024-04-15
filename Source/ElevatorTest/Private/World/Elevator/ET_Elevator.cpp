// Fill out your copyright notice in the Description page of Project Settings.

#include "ElevatorTest/Public/World/Elevator/ET_Elevator.h"

#include "ElevatorTest/ElevatorTestPlayerController.h"
#include "ElevatorTest/Public/Core/GameInstance/ET_GameInstance.h"


class AElevatorTestPlayerController;
// Sets default values
AET_Elevator::AET_Elevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ElevatorMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Elevator StaticMeshComponent");
	SetRootComponent(ElevatorMeshComp);
	ElevatorMeshComp->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void AET_Elevator::BeginPlay()
{
	Super::BeginPlay();

	if (UET_GameInstance* GI = Cast<UET_GameInstance>(GetGameInstance()))
	{
		GI->SetElevatorObject(this);
	}

	OnActorBeginOverlap.AddUniqueDynamic(this, &AET_Elevator::OnBeginOverlap); 
	OnActorEndOverlap.AddUniqueDynamic(this, &AET_Elevator::OnOverlapEnd);
}

void AET_Elevator::Tick(float DeltaTime)
{
	if (bShouldUpdateLocation)
	{
		// Get new location
		const int index = static_cast<int>(TargetFloor);
		const FVector NewLocation = FMath::VInterpTo(GetActorLocation(), TargetLevelLocation[index], DeltaTime, ElevatorSpeed);

		// Update the actor's location
		SetActorLocation(NewLocation);

		if (FVector::Dist(NewLocation, TargetLevelLocation[index]) <= 10.f)
		{
			// update status
			bShouldUpdateLocation = false;
		}
	}
}

void AET_Elevator::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
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

		if (UET_ElevatorWidget* ElevatorUI = Cast<UET_ElevatorWidget>(PC->GetElevatorUI()))
		{
			ElevatorUI->RequestFloorUI(true);
		}

		// Make cursor Game and UI
		PC->SetInputMode(FInputModeGameAndUI());
	}
}

void AET_Elevator::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		if (!PlayerCharacter) return;
		
		AElevatorTestPlayerController* PC = Cast<AElevatorTestPlayerController>(PlayerCharacter->GetController());
		if (!PC)
		{
			UE_LOG(LogTemp, Warning, TEXT("AET_ElevatorTrigger: PlayerController not valid"));
			return;
		}
		
		if (UET_ElevatorWidget* ElevatorUI = Cast<UET_ElevatorWidget>(PC->GetElevatorUI()))
		{
			ElevatorUI->RequestFloorUI(false);
		}

		// Make cursor Game and UI
		PC->SetInputMode(FInputModeGameOnly());

		PlayerCharacter = nullptr;
	}
}