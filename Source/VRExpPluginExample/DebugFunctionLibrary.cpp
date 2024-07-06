#include "DebugFunctionLibrary.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"

UDebugFunctionLibrary::UDebugFunctionLibrary()
{
}

UDebugFunctionLibrary::~UDebugFunctionLibrary()
{
}

bool UDebugFunctionLibrary::IsActorSelectedInEditor(AActor* Actor)
{
#if WITH_EDITOR
    if (GIsEditor && Actor)
    {
        return Actor->IsSelected();
    }
#endif
    return false;
}