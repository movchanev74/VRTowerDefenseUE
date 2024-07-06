// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretPart.h"

// Sets default values
ATurretPart::ATurretPart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the static mesh component
	GrippableStaticMeshComponent = CreateDefaultSubobject<UGrippableStaticMeshComponent>(TEXT("GrippableStaticMeshComponent"));
	GrippableStaticMeshComponent->VRGripInterfaceSettings.SlotDefaultGripType = EGripCollisionType::InteractiveCollisionWithPhysics;
	GrippableStaticMeshComponent->VRGripInterfaceSettings.FreeDefaultGripType = EGripCollisionType::InteractiveCollisionWithPhysics;


	RootComponent = GrippableStaticMeshComponent;

	// Create and attach the pin collider
	PinCollider = CreateDefaultSubobject<USphereComponent>(TEXT("PinCollider"));
	PinCollider->SetupAttachment(RootComponent);
	PinCollider->SetRelativeLocation(FVector::ZeroVector);
	PinCollider->InitSphereRadius(10.0f); // Set radius as needed

	// Bind the OnDrop event
	//OnDropped.AddDynamic(this, &AMyVRGrippableActor::OnDrop);
}

// Called when the game starts or when spawned
void ATurretPart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurretPart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

