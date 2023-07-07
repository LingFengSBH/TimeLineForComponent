// Copyright Sun BoHeng(LingFeng) 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/Public/TimerManager.h"
#include "Engine/World.h"
#include "Modules/ModuleManager.h"

class FTimeLineForComponentModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
