
//#pragma once
//
//#include "CoreMinimal.h"
//#include "AttributeSet.h"
//#include "WeaponAttributeSet.generated.h"
//
///**
// * 
// */
//UCLASS()
//class LYRAGAME_API UWeaponAttributeSet : public UAttributeSet
//{
//	GENERATED_BODY()
//	
//};
///*
#pragma once

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "WeaponAttributeSet.generated.h"

class UObject;
struct FFrame;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS(BlueprintType)
class LYRAGAME_API UWeaponAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UWeaponAttributeSet();

	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, Ammo);
	ATTRIBUTE_ACCESSORS(UWeaponAttributeSet, AmmoMax);

//protected:
	//UFUNCTION()
	//void OnRep_BaseDamage(const FGameplayAttributeData& OldValue);

	//UFUNCTION()
	//void OnRep_BaseHeal(const FGameplayAttributeData& OldValue);

private:

	// The base amount of damage to apply in the damage execution.
	//UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseDamage, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Ammo;

	// The base amount of healing to apply in the heal execution.
	//UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BaseHeal, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData AmmoMax;
};
//*/