#include "SnowyFalconCore.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FSnowyFalconCoreModule"

void FSnowyFalconCoreModule::StartupModule()
{
	FString OverrideEngineShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("SnowyFalconCore"))->GetBaseDir(), TEXT("OverrideEngineShaders"));
	auto& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
	ShaderSourceDirectoryMappings[EngineDefaultShaderVirtualDir] = OverrideEngineShaderDir;
}

void FSnowyFalconCoreModule::ShutdownModule()
{
	auto& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
	ShaderSourceDirectoryMappings[EngineDefaultShaderVirtualDir] = EngineDefaultShaderVirtualDir;
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSnowyFalconCoreModule, SnowyFalconCore)