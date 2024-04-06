// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/World/Elevator/ET_ElevatorWidget.h"
#include "ElevatorTestPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class ELEVATORTEST_API AElevatorTestPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	FORCEINLINE UUserWidget* GetElevatorUI() const { return ElevatorWidget; };
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
	virtual void BeginPlay() override;

	// End Actor interface

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Class", meta = (AllowPrivateAccess))
	TSubclassOf<UET_ElevatorWidget> ElevatorWidgetClass;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime Data", meta = (AllowPrivateAccess))
	TObjectPtr<UUserWidget> ElevatorWidget;
};
