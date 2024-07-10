// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Grippables/GrippableStaticMeshComponent.h"
#include "TurretBase.h"
#include "TurretPartContainerComponent.h"
#include "TurretPart.generated.h"

UCLASS()
class VREXPPLUGINEXAMPLE_API ATurretPart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurretPart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UGrippableStaticMeshComponent* GrippableStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* Pin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<ATurretPart*> AttachedParts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ATurretPart* ParentPart;

	AActor* ParentActor;

	UTurretPartContainerComponent* TurretPartContainer;

	UFUNCTION(BlueprintCallable)
	void Attach(UPrimitiveComponent* connector);

	void OnGripped(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation);

	void OnDropped(UGripMotionControllerComponent* GrippingController, const FBPActorGripInformation& GripInformation, bool bWasSocketed);

	UFUNCTION(BlueprintCallable)
	ATurretBase* GetBase();
	void NotifyBase();
};
