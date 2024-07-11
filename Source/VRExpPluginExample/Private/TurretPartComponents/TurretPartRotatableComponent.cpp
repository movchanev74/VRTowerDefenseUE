// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretPartComponents/TurretPartRotatableComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

UTurretPartRotatableComponent::UTurretPartRotatableComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    //MinAngle = -90.0f;
    //MaxAngle = 90.0f;
    //RotationSpeed = 30.0f;
    //DefaultAngle = 0.0f;
    //InterpSpeed = 5.0f; // Speed of interpolation
    //CurrentAngle = MinAngle;
    //bIsIncreasing = true;
}

void UTurretPartRotatableComponent::LookAt_Implementation(AActor* Target)
{
    UE_LOG(LogTemp, Warning, TEXT("LookAt_Implementation called"));
}

void UTurretPartRotatableComponent::Sleep_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Sleep_Implementation called"));
}

void UTurretPartRotatableComponent::BeginPlay()
{
    Super::BeginPlay();
}

//
//void UTurretPartRotatableComponent::Scan()
//{
//    GetWorld()->GetTimerManager().SetTimer(ScanTimerHandle, this, &UTurretPartRotatableComponent::UpdateRotation, 0, true, 0);
//}
//
//void UTurretPartRotatableComponent::Sleep()
//{
//    GetWorld()->GetTimerManager().ClearTimer(ScanTimerHandle);
//    //GetWorld()->GetTimerManager().SetTimer(SleepTimerHandle, this, &UTurretPartRotatableComponent::ResetRotation, 0, true, 0);
//}
//
//void UTurretPartRotatableComponent::UpdateRotation()
//{
//    float TargetAngle = bIsIncreasing ? MaxAngle : MinAngle;
//    CurrentAngle = FMath::FInterpTo(CurrentAngle, TargetAngle, GetWorld()->GetDeltaSeconds(), InterpSpeed);
//
//    if (FMath::IsNearlyEqual(CurrentAngle, TargetAngle, 1.0f))
//    {
//        bIsIncreasing = !bIsIncreasing;
//    }
//
//    FRotator NewRotation = GetOwner()->GetActorRotation();
//    NewRotation.Yaw = CurrentAngle; // Assuming the camera rotates around the Y-axis
//    GetOwner()->SetActorRotation(NewRotation);
//}
//
//void UTurretPartRotatableComponent::ResetRotation()
//{
//    CurrentAngle = FMath::FInterpTo(CurrentAngle, DefaultAngle, GetWorld()->GetDeltaSeconds(), InterpSpeed);
//
//    if (FMath::IsNearlyEqual(CurrentAngle, DefaultAngle, 1.0f))
//    {
//        GetWorld()->GetTimerManager().ClearTimer(SleepTimerHandle);
//    }
//
//    FRotator NewRotation = GetOwner()->GetActorRotation();
//    NewRotation.Yaw = CurrentAngle; // Assuming the camera rotates around the Y-axis
//    GetOwner()->SetActorRotation(NewRotation);
//}

// Called every frame
void UTurretPartRotatableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

