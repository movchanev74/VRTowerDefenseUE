// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "WeaponFireGameplayEffectContext.generated.h"

USTRUCT(BlueprintType)
struct FWeaponFireGameplayEffectContext : public FGameplayEffectContext
{
    GENERATED_BODY()
public:
    //bool IsFatalHit() const { return bIsFatalHit; }
    //bool IsCriticalHit() const { return bIsCriticalHit; }
    //float GetCartridgeID() const { return CartridgeID; }
    //float GetSourceLevel() const { return SourceLevel; }

    //void SetIsFatalHit(bool bInIsFatalHit) { bIsFatalHit = bInIsFatalHit; }
    //void SetIsCriticalHit(bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }
    //void SetCartridgeID(int32 InID) { CartridgeID = InID; }
    //void SetSourceLevel(float InLevel) { SourceLevel = InLevel; }

    // Новый массив для хранения точек попаданий
    //UFUNCTION(BlueprintPure, Category = "WeaponFire")
    const TArray<FVector>& GetHitLocations() const { return HitLocations; }
    void AddHitLocation(const FVector& Location) 
    { 
        if (HitLocations.IsValidIndex(0) || HitLocations.Num() == 0)  // Проверяем, что массив валиден
        {
            HitLocations.Add(Location);  // Добавляем элемент
        }
    }

protected:
    //UPROPERTY()
    //bool bIsFatalHit;

    //UPROPERTY()
    //bool bIsCriticalHit;

    //UPROPERTY()
    //int32 CartridgeID;

    //UPROPERTY()
    //float SourceLevel;

    // Массив точек попадания
    UPROPERTY(BlueprintReadWrite)
    TArray<FVector> HitLocations;

public:

    FWeaponFireGameplayEffectContext()
    {
        HitLocations.Empty(); // Явная инициализация
    }

    /** Returns the actual struct used for serialization, subclasses must override this! */
    virtual UScriptStruct* GetScriptStruct() const override
    {
        return StaticStruct();
    }

    virtual FWeaponFireGameplayEffectContext* Duplicate() const override
    {
        FWeaponFireGameplayEffectContext* NewContext = new FWeaponFireGameplayEffectContext(*this);
        NewContext->HitLocations = this->HitLocations;
        return NewContext;
    }

    virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override
    {
        Super::NetSerialize(Ar, Map, bOutSuccess);
        Ar << HitLocations;
        return true;
    }


    /** Creates a copy of this context, used to duplicate for later modifications */
    //virtual FWeaponFireGameplayEffectContext* Duplicate() const override
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Duplicate HitLocations"));
    //    FWeaponFireGameplayEffectContext* NewContext = new FWeaponFireGameplayEffectContext();
    //    *NewContext = *this;
    //    NewContext->AddActors(Actors);
    //    NewContext->HitLocations = HitLocations;  // Копируем точки попадания
    //    if (GetHitResult())
    //    {
    //        // Делает глубокую копию HitResult
    //        NewContext->AddHitResult(*GetHitResult(), true);
    //    }
    //    
    //    UE_LOG(LogTemp, Warning, TEXT("Duplicate HitLocations success " ));
    //    //UE_LOG(LogTemp, Warning, TEXT("%d"), HitLocations.Num());

    //    return NewContext;
    //}

    //virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;


};

template <>
struct TStructOpsTypeTraits<FWeaponFireGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FWeaponFireGameplayEffectContext>
{
    enum
    {
        WithNetSerializer = true,
        WithCopy = true // Necessary so that TSharedPtr<FHitResult> Data is copied around
    };
};