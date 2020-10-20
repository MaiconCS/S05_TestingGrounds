// AbraceTI


#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\ChooseNextWaypoint.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\AIController.h"
#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\PatrollingGuard.h" // TODO remove coupling
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\BehaviorTree\BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//TODO protect against empty patrol routes

	//Get the patrol points, 1º node
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	//Set Next Waypoint, 2º node
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle the Index, 3º node, use Mod = Rest of the division operator.
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	
	
	//UE_LOG(LogTemp, Warning, TEXT(" Waypoint index: %i "), Index);
	return EBTNodeResult::Succeeded;

}