#include "SetPatrolLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

USetPatrolLocation::USetPatrolLocation()
{
	NodeName = "Set Patrol Location";
}

EBTNodeResult::Type USetPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController) return EBTNodeResult::Failed;

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	TArray<AActor*> FoundPoints;

	UGameplayStatics::GetAllActorsOfClass(
		GetWorld(),
		PatrolPointClass,
		FoundPoints
	);

	if (FoundPoints.Num() == 0)
		return EBTNodeResult::Failed;

	int32 Index = FMath::RandRange(0, FoundPoints.Num() - 1);

	FVector SelectedLocation = FoundPoints[Index]->GetActorLocation();

	BlackboardComp->SetValueAsVector(PatrolLocationKey.SelectedKeyName, SelectedLocation);

	return EBTNodeResult::Succeeded;
}
