// Copyright (c) SnowyLake. All rights reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FSnowyFalconModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
