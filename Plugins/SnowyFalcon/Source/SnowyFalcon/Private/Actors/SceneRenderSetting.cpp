// Copyright (c) SnowyLake. All rights reserved.

#include "Actors/SceneRenderSetting.h"

#include "SystemTextures.h"
#include "SceneUniformBuffer.h"

ASceneRenderSetting::ASceneRenderSetting()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASceneRenderSetting::Tick(float DeltaTime)
{
	Parameters.TestColor = this->TestColor;
	Parameters.TestTexture = this->TestTexture;
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
	auto& Parameters = ASceneRenderSetting::Parameters;
	OutParameters.TestColor = Parameters.TestColor;
	OutParameters.TestTexture = Parameters.TestTexture ? Parameters.TestTexture->GetResource()->GetTexture2DRHI() : GSystemTextures.WhiteDummy->GetRHI();
	OutParameters.TestSampler = TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
}
}
IMPLEMENT_SCENE_UB_STRUCT(FSceneRenderSettingParameters, SceneRenderSetting, SnowyFalcon::SetSceneRenderSettingParameters);