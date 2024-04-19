#pragma once

#include "Modules/ModuleManager.h"

class FSnowyFalconCoreModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
private:
	static const inline FString EngineDefaultShaderVirtualDir = TEXT("/Engine");
	static const inline FString EngineDefaultShaderRealDir = FPaths::Combine(*(FPaths::EngineDir()), TEXT("Shaders"));
};
