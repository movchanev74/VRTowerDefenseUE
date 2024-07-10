// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TurretRotatablePartLookAt.h"


UBTTask_TurretRotatablePartLookAt::UBTTask_TurretRotatablePartLookAt()
{
    NodeName = "Turret Rotatable Part Look At";
    bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_TurretRotatablePartLookAt::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    return EBTNodeResult::InProgress;
}

void UBTTask_TurretRotatablePartLookAt::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
                for (UTurretPartRotatableComponent* Component : Turret->RotatableComponents)
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