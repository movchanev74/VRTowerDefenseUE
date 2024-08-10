// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurretPartScanerComponent.generated.h"


UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LYRAGAME_API UTurretPartScanerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties 
	UTurretPartScanerComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LookAt(AActor* Target);
	virtual void LookAt_Implementation(AActor* Target);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Scan();
	virtual void Scan_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Sleep();
	virtual void Sleep_Implementation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	FTimerHandle ScanTimerHandle;
	FTimerHandle SleepTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Scan")
	float MinAngle;

	UPROPERTY(EditAnywhere, Category = "Scan")
	float MaxAngle;

	//UPROPERTY(EditAnywhere, Category = "Scan")
	//float RotationSpeed; // Degrees per second

	UPROPERTY(EditAnywhere, Category = "Scan")
	float DefaultAngle; // Angle to return to when sleeping

	UPROPERTY(EditAnywhere, Category = "Scan")
	float InterpSpeed; // Speed of interpolation

	float CurrentAngle;
	bool bIsIncreasing;

public:
	void ResetRotation();
};


