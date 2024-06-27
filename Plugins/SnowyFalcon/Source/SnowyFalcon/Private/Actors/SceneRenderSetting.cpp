// Copyright (c) SnowyLake. All rights reserved.

#include "Actors/SceneRenderSetting.h"

#include "Utils/ShaderUtils.h"

#include "SystemTextures.h"
#include "SceneUniformBuffer.h"

FSceneRenderSettingParameterStruct::FSceneRenderSettingParameterStruct()
	: TestColor(FLinearColor::White)
	, TestTexture(nullptr)
{
}

ASceneRenderSetting::ASceneRenderSetting()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASceneRenderSetting::Tick(float DeltaTime)
{
	UBParameters.TestColor = Parameters.TestColor;
	UBParameters.TestTexture = Parameters.TestTexture;
}

BEGIN_SHADER_PARAMETER_STRUCT(FSceneRenderSettingParameters, SNOWYFALCON_API)
	SHADER_PARAMETER(FLinearColor, TestColor)
	SHADER_PARAMETER_TEXTURE(Texture2D, TestTexture)
	SHADER_PARAMETER_SAMPLER(SamplerState, TestSampler)
END_SHADER_PARAMETER_STRUCT()

DECLARE_SCENE_UB_STRUCT(FSceneRenderSettingParameters, SceneRenderSetting, SNOWYFALCON_API)

namespace SnowyFalcon
{
static void SetSceneRenderSettingParameters(FSceneRenderSettingParameters& OutParameters, FRDGBuilder& GraphBuilder)
{
	auto& UBParameters = ASceneRenderSetting::UBParameters;
	OutParameters.TestColor = UBParameters.TestColor;
	OutParameters.TestTexture = FShaderUtils::GetRHITextureOrDefault(UBParameters.TestTexture);
	OutParameters.TestSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
}
}
IMPLEMENT_SCENE_UB_STRUCT(FSceneRenderSettingParameters, SceneRenderSetting, SnowyFalcon::SetSceneRenderSettingParameters);