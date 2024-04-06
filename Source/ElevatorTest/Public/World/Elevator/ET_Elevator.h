// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ET_ElevatorTrigger.h"
#include "GameFramework/Actor.h"
#include "ElevatorTest/Public/Shell/ElevatorEnum.h"
#include "ET_Elevator.generated.h"

UCLASS()
class ELEVATORTEST_API AET_Elevator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AET_Elevator();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetTargetFloor(const EET_FloorLevel FloorLevel);
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EET_FloorLevel GetCurrentFloor() const { return CurrentElevatorLevel; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FVector GetFirstFloorLocation() const { return FirstFloorLocation; }

	UFUNCTION(BlueprintImplementableEvent)
	void MoveElevatorToTarget(const EET_FloorLevel FloorLevel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Elevator", meta = (AllowPrivateAccess))
	TObjectPtr<UStaticMeshComponent> ElevatorMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Elevator", meta = (AllowPrivateAccess))
	FVector FirstFloorLocation = FVector(0, 0, 0);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TEnumAsByte<EET_FloorLevel>CurrentElevatorLevel = level_1;

	UPROPERTY()
	TEnumAsByte<EET_FloorLevel> TargetFloor;

	UPROPERTY()
	TObjectPtr<AET_ElevatorTrigger> Trigger;
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	TSubclassOf<AET_ElevatorTrigger> TriggerClass;
};
