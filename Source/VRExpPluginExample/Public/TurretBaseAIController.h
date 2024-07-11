// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurretBaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API ATurretBaseAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATurretBaseAIController();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAIPerceptionComponent* CameraSensorPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)//, Category = "AI")
		AActor* myActor;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)//, Category = "AI")
	UAIPerceptionComponent* BackPerceptionComponent;

	//void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus) override;
};
