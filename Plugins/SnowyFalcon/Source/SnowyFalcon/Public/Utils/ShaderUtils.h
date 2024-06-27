// Copyright (c) SnowyLake. All rights reserved.

#pragma once

#include "SystemTextures.h"

namespace SnowyFalcon
{
class SNOWYFALCON_API FShaderUtils
{
public:
	static void ShaderSourceDirectoryRemapping();
	static void ShaderSourceDirectoryReset();

	static FRHITexture* GetRHITextureOrDefault(TObjectPtr<UTexture2D> Texture, TRefCountPtr<IPooledRenderTarget> Default = GSystemTextures.WhiteDummy);

	
public:
	static const inline FString EngineShaderVirtualDir = TEXT("/Engine");
	static const inline FString EngineShaderRealDir = FPaths::Combine(*(FPaths::EngineDir()), TEXT("Shaders"));
};
}

