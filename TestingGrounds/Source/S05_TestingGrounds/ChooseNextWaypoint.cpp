// AbraceTI


#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\ChooseNextWaypoint.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\AIController.h"
#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\PatrolRoute.h" 
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\BehaviorTree\BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	//Get the patrol points, 1 node
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if ( !ensure(PatrolRoute) )	{ return EBTNodeResult::Failed;	}
	
	//Warn about empty patrol routes
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0 ) 
	{
		UE_LOG(LogTemp, Warning, TEXT(" Not set a patrol point for guard"));
		return EBTNodeResult::Failed;
	}

	//Set Next Waypoint, 2 node
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle the Index, 3 node, use Mod = Rest of the division operator.
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
			
	
	//UE_LOG(LogTemp, Warning, TEXT(" Waypoint index: %i "), Index);
	return EBTNodeResult::Succeeded;

}