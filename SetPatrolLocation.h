#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetPatrolLocation.generated.h"


UCLASS()
class MOJPROJEKT_API USetPatrolLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	USetPatrolLocation();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector PatrolLocationKey;

	UPROPERTY(EditAnywhere, Category = "Patrol")
	TSubclassOf<AActor> PatrolPointClass;

private:
	int32 CurrentIndex = 0;
};
