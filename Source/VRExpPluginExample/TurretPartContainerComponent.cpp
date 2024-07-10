// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretPartContainerComponent.h"

// Sets default values for this component's properties
UTurretPartContainerComponent::UTurretPartContainerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTurretPartContainerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTurretPartContainerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTurretPartContainerComponent::AddTurretPart(ATurretPart* TurretPart)
{
	AttachedParts.Add(TurretPart);
}

void UTurretPartContainerComponent::RemoveTurretPart(ATurretPart* TurretPart)
{
	AttachedParts.Remove(TurretPart);
}

