#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurretGunBarrelShot.generated.h"

UCLASS(Category = "Turret", meta = (BlueprintSpawnableComponent))
class LYRAGAME_API UBTTask_TurretGunBarrelShot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretGunBarrelShot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};