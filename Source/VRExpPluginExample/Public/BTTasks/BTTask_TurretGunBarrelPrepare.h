#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurretGunBarrelPrepare.generated.h"

UCLASS(Category = "Turret", meta = (BlueprintSpawnableComponent))
class VREXPPLUGINEXAMPLE_API UBTTask_TurretGunBarrelPrepare : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretGunBarrelPrepare();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};