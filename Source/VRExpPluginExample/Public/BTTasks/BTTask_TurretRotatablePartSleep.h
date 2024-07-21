#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurretRotatablePartSleep.generated.h"

UCLASS(Category = "Turret", meta = (BlueprintSpawnableComponent))
class VREXPPLUGINEXAMPLE_API UBTTask_TurretRotatablePartSleep : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretRotatablePartSleep();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};