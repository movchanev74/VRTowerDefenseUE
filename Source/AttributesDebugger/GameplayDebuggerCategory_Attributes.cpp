#include "GameplayDebuggerCategory_Attributes.h"

#if WITH_GAMEPLAY_DEBUGGER

#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "AbilitySystemGlobals.h"
#include <AbilitySystemComponent.h>

FGameplayDebuggerCategory_Attributes::FGameplayDebuggerCategory_Attributes()
{
    SetDataPackReplication(&DataPack);
}

void FGameplayDebuggerCategory_Attributes::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
    if (!DebugActor) return;

    TMap<FString, float> attrMap = {};

    auto ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(DebugActor);
    if (IsValid(ASC)) {
        TArray<FGameplayAttribute> attrs;
        ASC->GetAllAttributes(attrs);
           
        for (auto attr : attrs) {
            bool bFound = false;
            float value = ASC->GetGameplayAttributeValue(attr, bFound);
            if (bFound) {
                attrMap.Add(attr.AttributeName, value);
            }
        }
    }

    DataPack.Attributes = attrMap;
}

void FGameplayDebuggerCategory_Attributes::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext)
{
    for (auto attr : DataPack.Attributes) {
        CanvasContext.Printf(TEXT("{yellow}%s: {white}%f"), *attr.Key, attr.Value);
    }
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Attributes::MakeInstance()
{
    return MakeShareable(new FGameplayDebuggerCategory_Attributes());
}

void FGameplayDebuggerCategory_Attributes::FRepData::Serialize(FArchive& Ar)
{
    Ar << Attributes;
}

#endif // WITH_GAMEPLAY_DEBUGGER