// AbraceTI


#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\ChooseNextWaypoint.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\BehaviorTree\BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT(" Waypoint index: %i "), Index);
	return EBTNodeResult::Succeeded;

}