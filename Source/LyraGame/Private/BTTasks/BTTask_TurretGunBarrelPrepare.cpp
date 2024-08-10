
#include "BTTasks/BTTask_TurretGunBarrelPrepare.h"

UBTTask_TurretGunBarrelPrepare::UBTTask_TurretGunBarrelPrepare()
{
    NodeName = "Gun Barrel Prepare";
    
    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretGunBarrelPrepare::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretGunBarrelPrepare::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        ATurretBase* Turret = Cast<ATurretBase>(AIController->GetPawn());
        if (Turret)
        {
            for (UTurretPartGunBarrelComponent* Component : Turret->GunBarrelComponents)
            {
                if (Component)
                {
                    Component->Prepare();
                }
            }
        }
    }
}

