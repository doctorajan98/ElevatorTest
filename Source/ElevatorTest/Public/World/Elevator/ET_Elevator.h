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
<<<<<<< HEAD
	FORCEINLINE void SetTargetFloor(const EET_FloorLevel FloorLevel)
	{
		TargetFloor = FloorLevel;
		MoveElevatorToTarget();
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetLocationState(const bool InBool) { bShouldUpdateLocation = InBool; }
=======
	FORCEINLINE void SetTargetFloor(const EET_FloorLevel FloorLevel);
>>>>>>> f91999ea239571828835d8b2b1b7290cd7acada0
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EET_FloorLevel GetCurrentFloor() const { return CurrentElevatorLevel; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE FVector GetFirstFloorLocation() const { return FirstFloorLocation; }
<<<<<<< HEAD
	
	void MoveElevatorToTarget() { bShouldUpdateLocation = true; };
=======

	UFUNCTION(BlueprintImplementableEvent)
	void MoveElevatorToTarget(const EET_FloorLevel FloorLevel);
>>>>>>> f91999ea239571828835d8b2b1b7290cd7acada0

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
<<<<<<< HEAD
	
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
=======
>>>>>>> f91999ea239571828835d8b2b1b7290cd7acada0

private:
	UPROPERTY(EditDefaultsOnly, Category = "Elevator", meta = (AllowPrivateAccess))
	TObjectPtr<UStaticMeshComponent> ElevatorMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Elevator", meta = (AllowPrivateAccess))
	FVector FirstFloorLocation = FVector(0, 0, 0);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TEnumAsByte<EET_FloorLevel>CurrentElevatorLevel = level_1;
<<<<<<< HEAD
=======

>>>>>>> f91999ea239571828835d8b2b1b7290cd7acada0
	UPROPERTY()
	TEnumAsByte<EET_FloorLevel> TargetFloor;

	UPROPERTY()
	TObjectPtr<AET_ElevatorTrigger> Trigger;
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess))
	TSubclassOf<AET_ElevatorTrigger> TriggerClass;
<<<<<<< HEAD

	UPROPERTY(EditAnywhere, Category = "Elevator", meta = (AllowPrivateAccess))
	TArray<FVector> TargetLevelLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Elevator", meta = (AllowPrivateAccess))
	float ElevatorSpeed = 5.f;
	
	UPROPERTY()
	TObjectPtr<AElevatorTestCharacter> PlayerCharacter;

	UPROPERTY()
	bool bShouldUpdateLocation = false;
=======
>>>>>>> f91999ea239571828835d8b2b1b7290cd7acada0
};
