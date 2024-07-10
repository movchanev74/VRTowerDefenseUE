#include "TurretPartScanerComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

UTurretPartScanerComponent::UTurretPartScanerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    MinAngle = -90.0f;
    MaxAngle = 90.0f;
    //RotationSpeed = 30.0f;
    DefaultAngle = 0.0f;
    InterpSpeed = 5.0f; // Speed of interpolation
    CurrentAngle = MinAngle;
    bIsIncreasing = true;
}

void UTurretPartScanerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UTurretPartScanerComponent::LookAt_Implementation(AActor* Target)
{

}

void UTurretPartScanerComponent::Scan_Implementation()
{
    FTransform ParentTransform = GetOwner()->GetAttachParentActor()->GetTransform();
    FQuat Rotation = ParentTransform.InverseTransformRotation(GetOwner()->GetActorTransform().GetRotation());
    FRotator Rotator = Rotation.Rotator();
    FRotator TargetRotator = Rotator;
    TargetRotator.Yaw = bIsIncreasing ? MaxAngle : MinAngle;
    Rotator = FMath::RInterpTo(Rotator, TargetRotator, GetWorld()->GetDeltaSeconds(), InterpSpeed);

    Rotation = Rotator.Quaternion();

    Rotation = ParentTransform.TransformRotation(Rotation);

    GetOwner()->SetActorRotation(Rotation);

    if (FMath::IsNearlyEqual(Rotator.Yaw, TargetRotator.Yaw, 1.0f))
    {
        bIsIncreasing = !bIsIncreasing;
    }
}

void UTurretPartScanerComponent::Sleep_Implementation()
{
    FTransform ParentTransform = GetOwner()->GetAttachParentActor()->GetTransform();
    FQuat Rotation = ParentTransform.InverseTransformRotation(GetOwner()->GetActorTransform().GetRotation());
    FRotator Rotator = Rotation.Rotator();
    FRotator TargetRotator = Rotator;
    TargetRotator.Yaw = bIsIncreasing ? MaxAngle : MinAngle;
    Rotator = FMath::RInterpTo(Rotator, TargetRotator, GetWorld()->GetDeltaSeconds(), InterpSpeed);

    Rotation = Rotator.Quaternion();

    Rotation = ParentTransform.TransformRotation(Rotation);

    GetOwner()->SetActorRotation(Rotation);

    //if (FMath::IsNearlyEqual(Rotator.Yaw, TargetRotator.Yaw, 1.0f))
    //{
    //    bIsIncreasing = !bIsIncreasing;
    //}
}

void UTurretPartScanerComponent::ResetRotation()
{
    CurrentAngle = FMath::FInterpTo(CurrentAngle, DefaultAngle, GetWorld()->GetDeltaSeconds(), InterpSpeed);

    if (FMath::IsNearlyEqual(CurrentAngle, DefaultAngle, 1.0f))
    {
        GetWorld()->GetTimerManager().ClearTimer(SleepTimerHandle);
    }

    FRotator NewRotation = GetOwner()->GetActorRotation();
    NewRotation.Yaw = CurrentAngle; // Assuming the camera rotates around the Y-axis
    GetOwner()->SetActorRotation(NewRotation);
}

void UTurretPartScanerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
