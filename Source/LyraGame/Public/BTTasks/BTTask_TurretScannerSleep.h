#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurretScannerSleep.generated.h"


UCLASS(Category = "Turret", meta = (BlueprintSpawnableComponent))
class LYRAGAME_API UBTTask_TurretScannerSleep : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretScannerSleep();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
