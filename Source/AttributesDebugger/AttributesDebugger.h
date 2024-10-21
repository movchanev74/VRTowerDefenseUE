#pragma once

#include "CoreMinimal.h"

class FAttributesDebugger : public IModuleInterface
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};