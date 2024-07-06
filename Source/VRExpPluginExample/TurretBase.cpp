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
    //if (CurrentPerceptionComponent == FrontPerceptionComponent)
    //{
    //    if (USkeletalMeshComponent* SkeletalMesh = GetMesh())
    //    {
    //        FTransform HeadTransform = SkeletalMesh->GetSocketTransform(FName("Head"), RTS_World);
    //        OutLocation = HeadTransform.GetLocation();
    //        OutRotation = HeadTransform.GetRotation().Rotator();
    //    }
    //}
    //else
    //{
        Super::GetActorEyesViewPoint(OutLocation, OutRotation);
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

