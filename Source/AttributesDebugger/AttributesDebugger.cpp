#include "AttributesDebugger.h"
#include "Modules/ModuleManager.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebugger.h"
#include "GameplayDebuggerCategory_Attributes.h"
#endif // WITH_GAMEPLAY_DEBUGGER

IMPLEMENT_MODULE( FAttributesDebugger, AttributesDebugger);

void FAttributesDebugger::StartupModule()
{
#if WITH_GAMEPLAY_DEBUGGER
    IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();

    GameplayDebuggerModule.RegisterCategory(
        "Attributes", 
        IGameplayDebugger::FOnGetCategory::CreateStatic(&FGameplayDebuggerCategory_Attributes::MakeInstance), 
        EGameplayDebuggerCategoryState::EnabledInGameAndSimulate, 
        3
    );

    GameplayDebuggerModule.NotifyCategoriesChanged();
#endif
}

void FAttributesDebugger::ShutdownModule()
{
}
