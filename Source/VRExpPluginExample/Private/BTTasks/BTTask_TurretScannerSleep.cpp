#include "BTTasks/BTTask_TurretScannerSleep.h"

UBTTask_TurretScannerSleep::UBTTask_TurretScannerSleep()
{
    NodeName = "Turret Scanner Sleep";
    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretScannerSleep::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretScannerSleep::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
                    Component->Sleep();
                }
            }
        }
    }
}