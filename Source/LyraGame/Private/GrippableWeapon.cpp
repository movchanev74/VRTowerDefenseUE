// Fill out your copyright notice in the Description page of Project Settings.


#include "GrippableWeapon.h"

AGrippableWeapon::AGrippableWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    // Create the Ability System Component
    //AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

    //if (AbilitySystemComponent)
    //{
        //HealthSet = CreateDefaultSubobject<ULyraHealthSet>(TEXT("HealthSet"));
    WeaponAttributeSet = CreateDefaultSubobject<UWeaponAttributeSet>(TEXT("WeaponAttributeSet"));
    //CombatSet = CreateDefaultSubobject<ULyraCombatSet>(TEXT("CombatSet"));
    //AbilitySystemComponent->InitStats(ULyraCombatSet::StaticClass(), nullptr);
//}
}