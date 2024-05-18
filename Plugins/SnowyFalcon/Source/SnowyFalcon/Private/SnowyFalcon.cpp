#include "SnowyFalcon.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FSnowyFalconModule"

void FSnowyFalconModule::StartupModule()
{
	auto&& OverrideRealShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("SnowyFalcon"))->GetBaseDir(), TEXT("Shaders"));
	auto&& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
	ShaderSourceDirectoryMappings[EngineDefaultShaderVirtualDir] = OverrideRealShaderDir;
}

void FSnowyFalconModule::ShutdownModule()
{
	auto&& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
	ShaderSourceDirectoryMappings[EngineDefaultShaderVirtualDir] = EngineDefaultShaderVirtualDir;
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSnowyFalconModule, SnowyFalcon)