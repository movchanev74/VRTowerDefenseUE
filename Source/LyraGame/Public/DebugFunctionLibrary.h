#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DebugFunctionLibrary.generated.h"

UCLASS()
class LYRAGAME_API UDebugFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UDebugFunctionLibrary();
    ~UDebugFunctionLibrary();
    UFUNCTION(BlueprintCallable, Category = "Editor")
    static bool IsActorSelectedInEditor(AActor* Actor);
};