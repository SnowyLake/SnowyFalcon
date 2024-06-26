#pragma once

namespace SnowyFalcon
{
class SNOWYFALCON_API FShaderUtils
{
public:
	static void ShaderSourceDirectoryRemapping();
	static void ShaderSourceDirectoryReset();
public:
	static const inline FString EngineShaderVirtualDir = TEXT("/Engine");
	static const inline FString EngineShaderRealDir = FPaths::Combine(*(FPaths::EngineDir()), TEXT("Shaders"));
};
}

