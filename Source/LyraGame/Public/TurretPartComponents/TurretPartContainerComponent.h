// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "TurretPart.h"
#include "Components/ActorComponent.h"
#include "TurretPartContainerComponent.generated.h"

class ATurretPart;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LYRAGAME_API UTurretPartContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTurretPartContainerComponent();

protected: 
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSet<ATurretPart*> AttachedParts;

	void AddTurretPart(ATurretPart* TurretPart);
	void RemoveTurretPart(ATurretPart* TurretPart);
};
