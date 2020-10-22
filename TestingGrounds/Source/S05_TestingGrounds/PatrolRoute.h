// AbraceTI

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\ActorComponent.h"
#include "PatrolRoute.generated.h"
/*
* A "route card" to help AI choose their next waypoint
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*>GetPatrolPoints() const;

private:

	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPoints;

};
