// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "ApplyRecoilAbilityTask.generated.h"

UCLASS(Blueprintable)
class LYRAGAME_API UApplyRecoilAbilityTask : public UAbilityTask
{
    GENERATED_BODY()

public:
    //UPROPERTY(BlueprintAssignable)
    //FSimpleDelegate OnRecoilReduced;

    UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "Apply Recoil Task"))
    static UApplyRecoilAbilityTask* CreateReduceRecoilTask(UGameplayAbility* OwningAbility, float InitialOffset, float Duration);

protected:
    virtual void Activate() override;
    virtual void TickTask(float DeltaTime) override;

private:
    float CurrentOffset;
    float TargetOffset;
    float ReductionRate;
};
