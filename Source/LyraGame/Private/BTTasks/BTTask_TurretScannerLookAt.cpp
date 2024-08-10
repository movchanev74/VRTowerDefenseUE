#include "BTTasks/BTTask_TurretScannerLookAt.h"


UBTTask_TurretScannerLookAt::UBTTask_TurretScannerLookAt()
{
    NodeName = "Scanner Look At";
    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretScannerLookAt::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretScannerLookAt::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        ATurretBase* Turret = Cast<ATurretBase>(AIController->GetPawn());
        if (Turret)
        {
            AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetActorKey.SelectedKeyName));
            if (TargetActor)
            {
                for (UTurretPartScanerComponent* Component : Turret->ScanerComponents)
                {
                    if (Component)
                    {
                        Component->LookAt(TargetActor);
                    }
                }
            }
        }
    }
}