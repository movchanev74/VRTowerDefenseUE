#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurretPartGunBarrelComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class VREXPPLUGINEXAMPLE_API UTurretPartGunBarrelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTurretPartGunBarrelComponent();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Shot();
	virtual void Shot_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Prepare();
	virtual void Prepare_Implementation();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
