#pragma once

#if WITH_GAMEPLAY_DEBUGGER

#include "CoreMinimal.h"
#include "GameplayDebuggerCategory.h"

class APlayerController;
class AActor;

class FGameplayDebuggerCategory_Attributes : public FGameplayDebuggerCategory
{
public:
    FGameplayDebuggerCategory_Attributes();
    void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
    void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;

    static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

protected:
    struct FRepData
    {
        TMap<FString, float> Attributes;

        void Serialize(FArchive& Ar);
    };

    FRepData DataPack;
};

#endif // WITH_GAMEPLAY_DEBUGGER