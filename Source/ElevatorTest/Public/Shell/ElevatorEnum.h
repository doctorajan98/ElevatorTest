#pragma once

#include "CoreMinimal.h"
#include "ElevatorEnum.generated.h"

UENUM(Blueprintable)
enum EET_FloorLevel
{
	level_1 UMETA(DisplayName = "Level 1"),
	level_2 UMETA(DisplayName = "Level 2"),
	level_3 UMETA(DisplayName = "Level 3"),
	level_4 UMETA(DisplayName = "Level 4"),
	level_5 UMETA(DisplayName = "Level 5"),
};
