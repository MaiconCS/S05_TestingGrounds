// AbraceTI

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Templates\TP_ThirdPerson\Source\TP_ThirdPerson\TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()



public:
	
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;

};
