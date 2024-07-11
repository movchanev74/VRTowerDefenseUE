// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretBase.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurretScan.generated.h"

/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API UBTTask_TurretScan : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_TurretScan();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};