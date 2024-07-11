// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretBase.h"

// Sets default values
ATurretBase::ATurretBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATurretBase::GetActorEyesViewPoint(FVector& OutLocation, FRotator& OutRotation) const
{
    Super::GetActorEyesViewPoint(OutLocation, OutRotation);

    if (ScanerComponents.Num() > 0)
    {
        auto ScanerTransform = ScanerComponents[0]->GetOwner()->GetTransform();
    
        //OutLocation = ScanerTransform.GetLocation();
        OutRotation = FRotator(0, ScanerTransform.GetRotation().Rotator().Yaw, 0);
    }

    //if (CurrentPerceptionComponent == FrontPerceptionComponent)
    //{
    //    if (USkeletalMeshComponent* SkeletalMesh = GetMesh())
    //    {
    //        FTransform HeadTransform = SkeletalMesh->GetSocketTransform(FName("Head"), RTS_World);
    //    }
    //}
    //else
    //{
        //Super::GetActorEyesViewPoint(OutLocation, OutRotation);
    //}
}

// Called when the game starts or when spawned
void ATurretBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATurretBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATurretBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATurretBase::TurretHierarchyUpdated()
{
    UE_LOG(LogTemp, Warning, TEXT("TurretHierarchyUpdated"));

    ScanerComponents.Empty();

    ScanForComponentsInTree<UTurretPartScanerComponent>(ScanerComponents);
    ScanForComponentsInTree<UTurretPartRotatableComponent>(RotatableComponents);
}

template <typename T>
void ATurretBase::ScanForComponentsInTree(TArray<T*>& OutComponents)
{
    TArray<UActorComponent*> TempComponents;
    ScanForComponentsRecursive(this, T::StaticClass(), TempComponents);

    for (UActorComponent* Component : TempComponents)
    {
        if (T* TypedComponent = Cast<T>(Component))
        {
            OutComponents.Add(TypedComponent);
        }
    }
}

void ATurretBase::ScanForComponentsRecursive(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass, TArray<UActorComponent*>& OutComponents)
{
    if (!Actor)
        return;

    TArray<UActorComponent*> Components;
    Actor->GetComponents(ComponentClass, Components);

    OutComponents.Append(Components);

    TArray<AActor*> AttachedActors;
    Actor->GetAttachedActors(AttachedActors);

    for (AActor* AttachedActor : AttachedActors)
    {
        ScanForComponentsRecursive(AttachedActor, ComponentClass, OutComponents);
    }
}

