#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_TurretRotatablePartLookAt.generated.h"

UCLASS(Category = "Turret", meta = (BlueprintSpawnableComponent))
class LYRAGAME_API UBTTask_TurretRotatablePartLookAt : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretRotatablePartLookAt();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetActorKey;
};
