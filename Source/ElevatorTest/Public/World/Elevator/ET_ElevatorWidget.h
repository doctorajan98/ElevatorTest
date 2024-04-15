// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ET_ElevatorWidget.generated.h"

/**
 * 
 */
UCLASS()
class ELEVATORTEST_API UET_ElevatorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CallElevatorUI(const bool bShouldOpen);

	UFUNCTION(BlueprintImplementableEvent)
	void RequestFloorUI(const bool bShouldOpen);
	
private:
	bool bCanPressUI = true;
};