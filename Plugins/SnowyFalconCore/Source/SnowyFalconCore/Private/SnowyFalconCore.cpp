#include "SnowyFalconCore.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FSnowyFalconCoreModule"

void FSnowyFalconCoreModule::StartupModule()
{
	FString OverrideRealShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("SnowyFalconCore"))->GetBaseDir(), TEXT("Shaders"));
	auto& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
	ShaderSourceDirectoryMappings[EngineDefaultShaderVirtualDir] = OverrideRealShaderDir;
}

void FSnowyFalconCoreModule::ShutdownModule()
{
	auto& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
	ShaderSourceDirectoryMappings[EngineDefaultShaderVirtualDir] = EngineDefaultShaderVirtualDir;
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSnowyFalconCoreModule, SnowyFalconCore)