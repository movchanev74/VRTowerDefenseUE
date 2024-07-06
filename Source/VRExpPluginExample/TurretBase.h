// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TurretBase.generated.h"

UCLASS()
class VREXPPLUGINEXAMPLE_API ATurretBase : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)//, Category = "AI")
	AActor* myActor;

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

};
