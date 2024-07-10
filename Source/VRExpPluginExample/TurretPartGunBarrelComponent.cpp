#include "TurretPartGunBarrelComponent.h"


UTurretPartGunBarrelComponent::UTurretPartGunBarrelComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTurretPartGunBarrelComponent::Shot_Implementation()
{

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

