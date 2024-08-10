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

	GrippableStaticMeshComponent->OnGripped.AddDynamic(this, &ATurretPart::OnGripped);
	GrippableStaticMeshComponent->OnDropped.AddDynamic(this, &ATurretPart::OnDropped);

	// Create and attach the pin collider
	Pin = CreateDefaultSubobject<USphereComponent>(TEXT("PinCollider"));
	Pin->SetupAttachment(RootComponent);
	Pin->SetRelativeLocation(FVector::ZeroVector);
	Pin->InitSphereRadius(10.0f); // Set radius as needed

	if (Pin)
	{
		UE_LOG(LogTemp, Warning, TEXT("PinCollider initialized successfully"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PinCollider initialization failed"));
	}
	// Bind the OnDrop event
	//OnDropped.AddDynamic(this, &AMyVRGrippableActor::OnDrop);
}

// Called when the game starts or when spawned
void ATurretPart::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ATurretPart::BeginPlay"));
}

// Called every frame
void ATurretPart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATurretPart::Attach(UPrimitiveComponent* connector)
{
	if (!connector)
		return;

	ParentActor = connector->GetOwner();

	TurretPartContainer = connector->GetOwner()->FindComponentByClass<UTurretPartContainerComponent>();
	if (TurretPartContainer)
	{
		TurretPartContainer->AddTurretPart(this);
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, true);
	AttachToComponent(connector->GetAttachParent(), AttachmentRules, connector->GetAttachSocketName());

	NotifyBase();
}

void ATurretPart::OnGripped(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation)
{
	if (TurretPartContainer)
	{
		TurretPartContainer->RemoveTurretPart(this);
	}

	TurretPartContainer = nullptr;
	NotifyBase();
}

void ATurretPart::OnDropped(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed)
{

}

ATurretBase* ATurretPart::GetBase()
{
	return nullptr;
}

void ATurretPart::NotifyBase()
{
	AActor* Parent = GetAttachParentActor();
	while (Parent)
	{
		if (ATurretBase* Base = Cast<ATurretBase>(Parent))
		{
			Base->TurretHierarchyUpdated();
			break;
		}
		Parent = Parent->GetAttachParentActor();
	}
}

