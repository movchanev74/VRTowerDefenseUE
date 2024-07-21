#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_TurretScannerLookAt.generated.h"

UCLASS(Category = "Turret", meta = (BlueprintSpawnableComponent))
class VREXPPLUGINEXAMPLE_API UBTTask_TurretScannerLookAt : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretScannerLookAt();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector TargetActorKey;
};
