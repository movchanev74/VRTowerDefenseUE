#include "BTTasks/BTTask_TurretRotatablePartSleep.h"


UBTTask_TurretRotatablePartSleep::UBTTask_TurretRotatablePartSleep()
{
    NodeName = "Rotatable Part Sleep";
    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretRotatablePartSleep::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretRotatablePartSleep::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        ATurretBase* Turret = Cast<ATurretBase>(AIController->GetPawn());
        if (Turret)
        {
            for (UTurretPartRotatableComponent* Component : Turret->RotatableComponents)
            {
                if (Component)
                {
                    Component->Sleep();
                }
            }
        }
    }
}