// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElevatorTest/ElevatorTestCharacter.h"
#include "ElevatorTest/Public/Shell/ElevatorEnum.h"
#include "Engine/TriggerVolume.h"
#include "ET_ElevatorTrigger.generated.h"

UENUM(BlueprintType)
enum E_ElevatorType
{
	call_Elevator UMETA(DisplayName = "Call Elevator"),
	request_floor UMETA(DisplayName = "Request Floor"),
};

/**
 * 
 */
UCLASS(BlueprintType)
class ELEVATORTEST_API AET_ElevatorTrigger : public ATriggerVolume
{
	GENERATED_BODY()	

public:
	AET_ElevatorTrigger();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE EET_FloorLevel GetCurrentLevel() const { return CurrentLevel; }
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
	
private:
	UPROPERTY()
	TObjectPtr<AElevatorTestCharacter> PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = " Elevator System", meta = (AllowPrivateAccess))
	TEnumAsByte<EET_FloorLevel>CurrentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "Elevator System", meta = (AllowPrivateAccess))
	TEnumAsByte<E_ElevatorType> ElevatorType;
};
