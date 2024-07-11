// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TurretPartComponents/TurretPartRotatableComponent.h"
#include "CoreMinimal.h"
#include "TurretPartComponents/TurretPartScanerComponent.h"
#include "GameFramework/Character.h"
#include "TurretBase.generated.h"

UCLASS()
class VREXPPLUGINEXAMPLE_API ATurretBase : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)//, Category = "AI")
	TArray<UTurretPartScanerComponent*> ScanerComponents;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UTurretPartRotatableComponent*> RotatableComponents;
	// Sets default values for this character's properties
	ATurretBase();

	virtual void GetActorEyesViewPoint(FVector& out_Location, FRotator& out_Rotation) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TurretHierarchyUpdated();

	template <typename T>
	void ScanForComponentsInTree(TArray<T*>& OutComponents);

private:
	void ScanForComponentsRecursive(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass, TArray<UActorComponent*>& OutComponents);
};