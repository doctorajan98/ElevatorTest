// Fill out your copyright notice in the Description page of Project Settings.

#include "ElevatorTest/Public/World/Elevator/ET_Elevator.h"
#include "World/Elevator/ET_Elevator.h"

#include "ElevatorTest/Public/Core/GameInstance/ET_GameInstance.h"
#include "ElevatorTest/Public/World/Elevator/ET_ElevatorWidget.h"

// Sets default values
AET_Elevator::AET_Elevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ElevatorMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Elevator StaticMeshComponent");
	SetRootComponent(ElevatorMeshComp);
	ElevatorMeshComp->SetMobility(EComponentMobility::Movable);

	Trigger = CreateDefaultSubobject<AET_ElevatorTrigger>("Trigger");
	AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AET_Elevator::BeginPlay()
{
	Super::BeginPlay();

	if (UET_GameInstance* GI = Cast<UET_GameInstance>(GetGameInstance()))
	{
		GI->SetElevatorObject(this);
	}
}

// Called every frame
void AET_Elevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AET_Elevator::SetTargetFloor(const EET_FloorLevel FloorLevel)
{
	TargetFloor = FloorLevel;
	MoveElevatorToTarget(TargetFloor);
}

