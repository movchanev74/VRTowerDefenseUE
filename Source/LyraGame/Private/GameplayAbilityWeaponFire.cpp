// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityWeaponFire.h"
#include <GrippableWeapon.h>
#include <AbilitySystem/LyraGameplayAbilityTargetData_SingleTargetHit.h>

//void UGameplayAbilityWeaponFire::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
//{
//	// Bind target data callback
//	UAbilitySystemComponent* MyAbilityComponent = CurrentActorInfo->AbilitySystemComponent.Get();
//	check(MyAbilityComponent);
//
//	OnTargetDataReadyCallbackDelegateHandle = MyAbilityComponent
//		->AbilityTargetDataSetDelegate(CurrentSpecHandle, CurrentActivationInfo.GetActivationPredictionKey())
//		.AddUObject(this, &ThisClass::OnTargetDataReadyCallback);
//
//	// Update the last firing time
//	ULyraRangedWeaponInstance* WeaponData = GetWeaponInstance();
//	check(WeaponData);
//	WeaponData->UpdateFiringTime();
//
//	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
//}


//void UGameplayAbilityWeaponFire::TraceBulletsInCartridge(const FRangedWeaponFiringInput& InputData, OUT TArray<FHitResult>& OutHits)
//void UGameplayAbilityWeaponFire::TraceBulletsInCartridge(OUT TArray<FHitResult>& OutHits)
//void UGameplayAbilityWeaponFire::TraceBulletsInCartridge(TArray<FHitResult>& OutHits)
void UGameplayAbilityWeaponFire::TraceBulletsInCartridge(FGameplayAbilityTargetDataHandle& TargetData)
{
	TArray<FHitResult> OutHits;

	auto weaponActor = Cast<AGrippableWeapon>(GetOwningActorFromActorInfo());
	auto muzzleTransform = weaponActor->GetMuuzleTransform();
	
	FRangedWeaponFiringInput InputData;

	InputData.AimDir = muzzleTransform.GetUnitAxis(EAxis::X);
	//InputData.AimDir = muzzleTransform.GetRotation();// TargetTransform.GetUnitAxis(EAxis::X);
	InputData.StartTrace = muzzleTransform.GetLocation();
	//InputData.EndAim = InputData.StartTrace + InputData.AimDir * WeaponData->GetMaxDamageRange();

	//ULyraRangedWeaponInstance* WeaponData = InputData.WeaponData;
	//check(WeaponData);

	const int32 BulletsPerCartridge = 5;//WeaponData->GetBulletsPerCartridge();

	for (int32 BulletIndex = 0; BulletIndex < BulletsPerCartridge; ++BulletIndex)
	{
		const float BaseSpreadAngle = 10;// WeaponData->GetCalculatedSpreadAngle();
		const float SpreadAngleMultiplier = 1;// WeaponData->GetCalculatedSpreadAngleMultiplier();
		const float ActualSpreadAngle = BaseSpreadAngle * SpreadAngleMultiplier;

		const float HalfSpreadAngleInRadians = FMath::DegreesToRadians(ActualSpreadAngle * 0.5f);

		const FVector BulletDir = VRandConeNormalDistribution(InputData.AimDir, HalfSpreadAngleInRadians, 0.8f);// WeaponData->GetSpreadExponent());

		//auto weaponActor = Cast<AGrippableWeapon>(GetOwningActorFromActorInfo());
		//auto muzzleTransform = weaponActor->GetMuuzleTransform();


		//const FVector EndTrace = muzzleTransform.GetLocation() + (BulletDir * 25000);// WeaponData->GetMaxDamageRange());
		const FVector EndTrace = InputData.StartTrace + (BulletDir * 25000);// WeaponData->GetMaxDamageRange());
		FVector HitLocation = EndTrace;

		TArray<FHitResult> AllImpacts;

		FHitResult Impact = DoSingleBulletTrace(InputData.StartTrace , EndTrace, /* WeaponData->GetBulletTraceSweepRadius()*/ 5.5f, /*bIsSimulated=*/ false, /*out*/ AllImpacts);

		const AActor* HitActor = Impact.GetActor();

		if (HitActor)
		{
//#if ENABLE_DRAW_DEBUG
			{
				DrawDebugPoint(GetWorld(), Impact.ImpactPoint, 1, FColor::Red, false, 1);
			}
//#endif

			if (AllImpacts.Num() > 0)
			{
				OutHits.Append(AllImpacts);
			}

			HitLocation = Impact.ImpactPoint;
		}

		// Make sure there's always an entry in OutHits so the direction can be used for tracers, etc...
		if (OutHits.Num() == 0)
		{
			if (!Impact.bBlockingHit)
			{
				// Locate the fake 'impact' at the end of the trace
				Impact.Location = EndTrace;
				Impact.ImpactPoint = EndTrace;
			}

			OutHits.Add(Impact);
		}
	}


	//FGameplayAbilityTargetDataHandle TargetData;
	//TargetData.UniqueId = WeaponStateComponent ? WeaponStateComponent->GetUnconfirmedServerSideHitMarkerCount() : 0;

	if (OutHits.Num() > 0)
	{
		const int32 CartridgeID = FMath::Rand();

		for (const FHitResult& FoundHit : OutHits)
		{
			FLyraGameplayAbilityTargetData_SingleTargetHit* NewTargetData = new FLyraGameplayAbilityTargetData_SingleTargetHit();
			NewTargetData->HitResult = FoundHit;
			NewTargetData->CartridgeID = CartridgeID;

			TargetData.Add( NewTargetData);
		}
	}

	//// Send hit marker information
	//const bool bProjectileWeapon = false;
	//if (!bProjectileWeapon && (WeaponStateComponent != nullptr))
	//{
	//	WeaponStateComponent->AddUnconfirmedServerSideHitMarkers(TargetData, FoundHits);
	//}
}

FVector UGameplayAbilityWeaponFire::VRandConeNormalDistribution(const FVector& Dir, const float ConeHalfAngleRad, const float Exponent)
{
	if (ConeHalfAngleRad > 0.f)
	{
		const float ConeHalfAngleDegrees = FMath::RadiansToDegrees(ConeHalfAngleRad);

		// consider the cone a concatenation of two rotations. one "away" from the center line, and another "around" the circle
		// apply the exponent to the away-from-center rotation. a larger exponent will cluster points more tightly around the center
		const float FromCenter = FMath::Pow(FMath::FRand(), Exponent);
		const float AngleFromCenter = FromCenter * ConeHalfAngleDegrees;
		const float AngleAround = FMath::FRand() * 360.0f;

		FRotator Rot = Dir.Rotation();
		FQuat DirQuat(Rot);
		FQuat FromCenterQuat(FRotator(0.0f, AngleFromCenter, 0.0f));
		FQuat AroundQuat(FRotator(0.0f, 0.0, AngleAround));
		FQuat FinalDirectionQuat = DirQuat * AroundQuat * FromCenterQuat;
		FinalDirectionQuat.Normalize();

		return FinalDirectionQuat.RotateVector(FVector::ForwardVector);
	}
	else
	{
		return Dir.GetSafeNormal();
	}
}

FHitResult UGameplayAbilityWeaponFire::DoSingleBulletTrace(const FVector& StartTrace, const FVector& EndTrace, float SweepRadius, bool bIsSimulated, OUT TArray<FHitResult>& OutHits) const
{
	//#if ENABLE_DRAW_DEBUG
	static float DebugThickness = 1.0f;
	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Red, false, 1, 0, DebugThickness);
	//#endif 

	FHitResult Impact;

	// Trace and process instant hit if something was hit
	// First trace without using sweep radius
	if (FindFirstPawnHitResult(OutHits) == INDEX_NONE)
	{
		Impact = WeaponTrace(StartTrace, EndTrace, /*SweepRadius=*/ 0.0f, bIsSimulated, /*out*/ OutHits);
	}

	if (FindFirstPawnHitResult(OutHits) == INDEX_NONE)
	{
		// If this weapon didn't hit anything with a line trace and supports a sweep radius, try that
		if (SweepRadius > 0.0f)
		{
			TArray<FHitResult> SweepHits;
			Impact = WeaponTrace(StartTrace, EndTrace, SweepRadius, bIsSimulated, /*out*/ SweepHits);

			// If the trace with sweep radius enabled hit a pawn, check if we should use its hit results
			const int32 FirstPawnIdx = FindFirstPawnHitResult(SweepHits);
			if (SweepHits.IsValidIndex(FirstPawnIdx))
			{
				// If we had a blocking hit in our line trace that occurs in SweepHits before our
				// hit pawn, we should just use our initial hit results since the Pawn hit should be blocked
				bool bUseSweepHits = true;
				for (int32 Idx = 0; Idx < FirstPawnIdx; ++Idx)
				{
					const FHitResult& CurHitResult = SweepHits[Idx];

					auto Pred = [&CurHitResult](const FHitResult& Other)
						{
							return Other.HitObjectHandle == CurHitResult.HitObjectHandle;
						};
					if (CurHitResult.bBlockingHit && OutHits.ContainsByPredicate(Pred))
					{
						bUseSweepHits = false;
						break;
					}
				}

				if (bUseSweepHits)
				{
					OutHits = SweepHits;
				}
			}
		}
	}

	return Impact;
}

int32 UGameplayAbilityWeaponFire::FindFirstPawnHitResult(const TArray<FHitResult>& HitResults)
{
	for (int32 Idx = 0; Idx < HitResults.Num(); ++Idx)
	{
		const FHitResult& CurHitResult = HitResults[Idx];
		if (CurHitResult.HitObjectHandle.DoesRepresentClass(APawn::StaticClass()))
		{
			// If we hit a pawn, we're good
			return Idx;
		}
		else
		{
			AActor* HitActor = CurHitResult.HitObjectHandle.FetchActor();
			if ((HitActor != nullptr) && (HitActor->GetAttachParentActor() != nullptr) && (Cast<APawn>(HitActor->GetAttachParentActor()) != nullptr))
			{
				// If we hit something attached to a pawn, we're good
				return Idx;
			}
		}
	}

	return INDEX_NONE;
}

FHitResult UGameplayAbilityWeaponFire::WeaponTrace(const FVector& StartTrace, const FVector& EndTrace, float SweepRadius, bool bIsSimulated, OUT TArray<FHitResult>& OutHitResults) const
{
	TArray<FHitResult> HitResults;

	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(WeaponTrace), /*bTraceComplex=*/ true, /*IgnoreActor=*/ GetAvatarActorFromActorInfo());
	TraceParams.bReturnPhysicalMaterial = true;
	AddAdditionalTraceIgnoreActors(TraceParams);
	//TraceParams.bDebugQuery = true;

	const ECollisionChannel TraceChannel = DetermineTraceChannel(TraceParams, bIsSimulated);

	if (SweepRadius > 0.0f)
	{
		GetWorld()->SweepMultiByChannel(HitResults, StartTrace, EndTrace, FQuat::Identity, TraceChannel, FCollisionShape::MakeSphere(SweepRadius), TraceParams);
	}
	else
	{
		GetWorld()->LineTraceMultiByChannel(HitResults, StartTrace, EndTrace, TraceChannel, TraceParams);
	}

	FHitResult Hit(ForceInit);
	if (HitResults.Num() > 0)
	{
		// Filter the output list to prevent multiple hits on the same actor;
		// this is to prevent a single bullet dealing damage multiple times to
		// a single actor if using an overlap trace
		for (FHitResult& CurHitResult : HitResults)
		{
			auto Pred = [&CurHitResult](const FHitResult& Other)
				{
					return Other.HitObjectHandle == CurHitResult.HitObjectHandle;
				};

			if (!OutHitResults.ContainsByPredicate(Pred))
			{
				OutHitResults.Add(CurHitResult);
			}
		}

		Hit = OutHitResults.Last();
	}
	else
	{
		Hit.TraceStart = StartTrace;
		Hit.TraceEnd = EndTrace;
	}

	return Hit;
}

//fix later
#define Lyra_TraceChannel_Weapon						ECC_GameTraceChannel2

ECollisionChannel UGameplayAbilityWeaponFire::DetermineTraceChannel(FCollisionQueryParams& TraceParams, bool bIsSimulated) const
{
	return Lyra_TraceChannel_Weapon;
}

void UGameplayAbilityWeaponFire::AddAdditionalTraceIgnoreActors(FCollisionQueryParams& TraceParams) const
{
	if (AActor* Avatar = GetAvatarActorFromActorInfo())
	{
		// Ignore any actors attached to the avatar doing the shooting
		TArray<AActor*> AttachedActors;
		Avatar->GetAttachedActors(/*out*/ AttachedActors);
		TraceParams.AddIgnoredActors(AttachedActors);
	}
}