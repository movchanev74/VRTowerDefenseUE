// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretBaseAIController.h"
//#include <Perception/AISenseConfig_Sight.h>
#include "Perception/AIPerceptionComponent.h"
#include <Perception/AISenseConfig_Sight.h>

ATurretBaseAIController::ATurretBaseAIController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSensorPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("CameraSensorPerceptionComponent"));

	UAISenseConfig_Sight* FrontSightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("FrontSightConfig"));
	FrontSightConfig->SightRadius = 1000.0f;
	FrontSightConfig->LoseSightRadius = 1200.0f;
	FrontSightConfig->PeripheralVisionAngleDegrees = 90.0f;

	CameraSensorPerceptionComponent->ConfigureSense(*FrontSightConfig);
	CameraSensorPerceptionComponent->SetDominantSense(UAISense_Sight::StaticClass());
}

//void ATurretBaseAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
//{
//
//}
