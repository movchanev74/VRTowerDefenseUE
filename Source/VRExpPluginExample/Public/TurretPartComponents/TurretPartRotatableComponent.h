// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurretPartRotatableComponent.generated.h"


UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VREXPPLUGINEXAMPLE_API UTurretPartRotatableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTurretPartRotatableComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LookAt(AActor* Target);
	virtual void LookAt_Implementation(AActor* Target);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Sleep();
	virtual void Sleep_Implementation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
