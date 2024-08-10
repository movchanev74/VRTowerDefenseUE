#include "BTTasks/BTTask_TurretScan.h"


UBTTask_TurretScan::UBTTask_TurretScan()
{
    NodeName = "Turret Start Scan";
    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretScan::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretScan::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        ATurretBase* Turret = Cast<ATurretBase>(AIController->GetPawn());
        if (Turret)
        {
            for (UTurretPartScanerComponent* Component : Turret->ScanerComponents)
            {
                if (Component)
                {
                    Component->Scan();
                }
            }
        }
    }
}
