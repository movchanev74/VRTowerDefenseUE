#include "TurretPartComponents/TurretPartGunBarrelComponent.h"

UTurretPartGunBarrelComponent::UTurretPartGunBarrelComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTurretPartGunBarrelComponent::Shot_Implementation()
{
    FVector Start = GetComponentLocation();
    FVector ForwardVector = GetForwardVector();
    FVector End = ((ForwardVector * 10000.f) + Start);
    FHitResult HitResult;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);

    if (bHit)
    {
        //UImpactHandler::HandleImpact(HitResult, GetWorld(), GroundImpactEffect, TreeImpactEffect, DefaultImpactEffect);
    }

    //PlayShotEffects();
}

void UTurretPartGunBarrelComponent::Prepare_Implementation()
{

}

void UTurretPartGunBarrelComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTurretPartGunBarrelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

