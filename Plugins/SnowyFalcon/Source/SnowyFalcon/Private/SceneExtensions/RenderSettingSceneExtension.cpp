// #include "SceneExtensions/RenderSettingSceneExtension.h"
//
// BEGIN_SHADER_PARAMETER_STRUCT(FCustomRenderSettingParameters, SNOWYFALCON_API)
// 	SHADER_PARAMETER(FVector3f, GlobalToonColor)
// END_SHADER_PARAMETER_STRUCT()
//
// DECLARE_SCENE_UB_STRUCT(FCustomRenderSettingParameters, CustomRenderSetting, SNOWYFALCON_API)
//
// namespace SnowyFalcon
// {
// static void GetDefaultCustomRenderSettingParameters(FCustomRenderSettingParameters& OutParameters, FRDGBuilder& GraphBuilder)
// {
// 	OutParameters.GlobalToonColor = FVector3f(1.0f, 0.0f, 0.0f);
// }
//
//
// // FRenderSettingSceneExtension
// // -----------------------------------------------------------------------------
// // Error, no export
// // IMPLEMENT_SCENE_EXTENSION(FRenderSettingSceneExtension);
//
// bool FRenderSettingSceneExtension::ShouldCreateExtension(FScene& InScene)
// {
// 	return true;
// }
//
// ISceneExtensionUpdater* FRenderSettingSceneExtension::CreateUpdater()
// {
// 	return new FRenderSettingSceneExtensionUpdater(*this);
// }
//
// ISceneExtensionRenderer* FRenderSettingSceneExtension::CreateRenderer()
// {
// 	return new FRenderSettingSceneExtensionRenderer(*this);
// }
//
//
// // FRenderSettingSceneExtensionUpdater
// // -----------------------------------------------------------------------------
// void FRenderSettingSceneExtensionUpdater::PreSceneUpdate(FRDGBuilder& GraphBuilder, const FScenePreUpdateChangeSet& ChangeSet)
// {
//
// }
//
// void FRenderSettingSceneExtensionUpdater::PostSceneUpdate(FRDGBuilder& GraphBuilder, const FScenePostUpdateChangeSet& ChangeSet)
// {
// 	
// }
//
// void FRenderSettingSceneExtensionUpdater::PostGPUSceneUpdate(FRDGBuilder& GraphBuilder,  FSceneUniformBuffer& SceneUniforms)
// {
//
// }
//
//
// // FRenderSettingSceneExtensionRenderer
// // -----------------------------------------------------------------------------
// void FRenderSettingSceneExtensionRenderer::UpdateSceneUniformBuffer(FRDGBuilder& GraphBuilder, FSceneUniformBuffer& SceneUniforms)
// {
// 	FCustomRenderSettingParameters Params;
// 	Params.GlobalToonColor = FVector3f(0.0f, 1.0f, 0.0f);
//
// 	SceneUniforms.Set(SceneUB::CustomRenderSetting, Params);
// }
// }
//
// IMPLEMENT_SCENE_UB_STRUCT(FCustomRenderSettingParameters, CustomRenderSetting, SnowyFalcon::GetDefaultCustomRenderSettingParameters);