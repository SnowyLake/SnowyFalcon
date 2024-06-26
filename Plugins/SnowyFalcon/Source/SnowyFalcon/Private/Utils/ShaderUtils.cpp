#include "Utils/ShaderUtils.h"

#include "Utils/SnowyFalconSetting.h"

namespace SnowyFalcon
{
void FShaderUtils::ShaderSourceDirectoryRemapping()
{
	if (auto&& Setting = FSetting::Get(); Setting.bShaderSourceRemapping)
	{
		auto&& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());

		if (FString RemappingRealShaderDir = FPaths::Combine(FPaths::ProjectDir(), Setting.ShaderSourceRemappingDirectory);
			FPaths::DirectoryExists(RemappingRealShaderDir))
		{
			ShaderSourceDirectoryMappings[EngineShaderVirtualDir] = RemappingRealShaderDir;
			UE_LOG(LogSnowyFalcon, Log, TEXT("Remapping engine shader source directory to %s"), *RemappingRealShaderDir);
		}
		else
		{
			UE_LOG(LogSnowyFalcon, Log, TEXT("Engine shader source remapping directory is not exist: %s"), *RemappingRealShaderDir);
		}
	}
}

void FShaderUtils::ShaderSourceDirectoryReset()
{
	if (auto&& Setting = FSetting::Get(); Setting.bShaderSourceRemapping)
	{
		auto&& ShaderSourceDirectoryMappings = const_cast<TMap<FString, FString>&>(AllShaderSourceDirectoryMappings());
		ShaderSourceDirectoryMappings[EngineShaderVirtualDir] = EngineShaderVirtualDir;
	}
}
}
