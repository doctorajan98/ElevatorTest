// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElevatorTest/Public/World/Elevator/ET_Elevator.h"
#include "Engine/GameInstance.h"
#include "ET_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ELEVATORTEST_API UET_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORCEINLINE AET_Elevator* GetElevator() const { return Elevator; }

	FORCEINLINE void SetElevatorObject(AET_Elevator* NewElevator) { Elevator = NewElevator; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE EET_FloorLevel GetCurrentFloor() const { return PlayerCurrentLevel; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetCurrentFloor(EET_FloorLevel Level) { PlayerCurrentLevel = Level; }

private:
	UPROPERTY()
	TObjectPtr<AET_Elevator> Elevator;

	UPROPERTY()
	TEnumAsByte<EET_FloorLevel>PlayerCurrentLevel;
};
