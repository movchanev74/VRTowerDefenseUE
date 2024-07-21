#include "BTTasks/BTTask_TurretGunBarrelShot.h"

UBTTask_TurretGunBarrelShot::UBTTask_TurretGunBarrelShot()
{
    NodeName = "Gun Barrel Shot";

    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretGunBarrelShot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretGunBarrelShot::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
                    Component->Shot();
                }
            }
        }
    }
}