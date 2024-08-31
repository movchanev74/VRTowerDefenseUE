// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbilityWeaponFire.generated.h"

UCLASS()
class LYRAGAME_API UGameplayAbilityWeaponFire : public UGameplayAbility
{
	GENERATED_BODY()

public:
	//virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
protected:
	struct FRangedWeaponFiringInput
	{
		// Start of the trace
		FVector StartTrace;

		// End of the trace if aim were perfect
		FVector EndAim;

		// The direction of the trace if aim were perfect
		FVector AimDir;

		// The weapon instance / source of weapon data
		//ULyraRangedWeaponInstance* WeaponData = nullptr;

		// Can we play bullet FX for hits during this trace
		//bool bCanPlayBulletFX = false;

		FRangedWeaponFiringInput()
			: StartTrace(ForceInitToZero)
			, EndAim(ForceInitToZero)
			, AimDir(ForceInitToZero)
		{
		}
	};

protected:
	static int32 FindFirstPawnHitResult(const TArray<FHitResult>& HitResults);

	FHitResult WeaponTrace(const FVector& StartTrace, const FVector& EndTrace, float SweepRadius, bool bIsSimulated, OUT TArray<FHitResult>& OutHitResults) const;

	FHitResult DoSingleBulletTrace(const FVector& StartTrace, const FVector& EndTrace, float SweepRadius, bool bIsSimulated, OUT TArray<FHitResult>& OutHits) const;
	
	virtual void AddAdditionalTraceIgnoreActors(FCollisionQueryParams& TraceParams) const;
	virtual ECollisionChannel DetermineTraceChannel(FCollisionQueryParams& TraceParams, bool bIsSimulated) const;
	
	FVector VRandConeNormalDistribution(const FVector& Dir, const float ConeHalfAngleRad, const float Exponent);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void TraceBulletsInCartridge(UPARAM(DisplayName = "Out Hits") TArray<FHitResult>& OutHits);


	//UFUNCTION(BlueprintCallable)
	//void TraceBulletsInCartridge(OUT TArray<FHitResult>& OutHits);
	//void TraceBulletsInCartridge(const FRangedWeaponFiringInput& InputData, OUT TArray<FHitResult>& OutHits);
};
