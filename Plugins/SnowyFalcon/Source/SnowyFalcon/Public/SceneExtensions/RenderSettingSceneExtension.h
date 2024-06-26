// Copyright (c) SnowyLake. All rights reserved.
//
// #pragma once
//
// #include "CoreMinimal.h"
// #include "SceneUniformBuffer.h"
// #include "RHIShaderPlatform.h"
// #include "RendererInterface.h"
// #include "RenderGraphResources.h"
// #include "SceneExtensions.h"
//
// namespace SnowyFalcon
// {
// // FRenderSettingSceneExtension
// // -----------------------------------------------------------------------------
// class FRenderSettingSceneExtension : public ISceneExtension
// {
// 	friend class FRenderSettingSceneExtensionUpdater;
// 	friend class FRenderSettingSceneExtensionRenderer;
//
// 	DECLARE_SCENE_EXTENSION(FRenderSettingSceneExtension);
//
// public:
// 	static bool ShouldCreateExtension(FScene& InScene);
//
// 	virtual void InitExtension(FScene& InScene) override { Scene = &InScene; }
// 	virtual ISceneExtensionUpdater* CreateUpdater() override;
// 	virtual ISceneExtensionRenderer* CreateRenderer() override;
//
// private:
// 	FScene* Scene = nullptr;
// };
//
//
// // FRenderSettingSceneExtensionUpdater
// // -----------------------------------------------------------------------------
// class FRenderSettingSceneExtensionUpdater : public ISceneExtensionUpdater
// {
// 	DECLARE_SCENE_EXTENSION_UPDATER(FRenderSettingSceneExtensionUpdater, FRenderSettingSceneExtension);
//
// public:
// 	FRenderSettingSceneExtensionUpdater(FRenderSettingSceneExtension& InSceneData) : SceneData(&InSceneData) {}
//
// 	virtual void PreSceneUpdate(FRDGBuilder& GraphBuilder, const FScenePreUpdateChangeSet& ChangeSet) override;
// 	virtual void PostSceneUpdate(FRDGBuilder& GraphBuilder, const FScenePostUpdateChangeSet& ChangeSet) override;
// 	virtual void PostGPUSceneUpdate(FRDGBuilder& GraphBuilder, FSceneUniformBuffer& SceneUniforms) override;
// 	
// private:
// 	FRenderSettingSceneExtension* SceneData = nullptr;
// };
//
//
// // FRenderSettingSceneExtensionRenderer
// // -----------------------------------------------------------------------------
// class FRenderSettingSceneExtensionRenderer : public ISceneExtensionRenderer
// {
// 	DECLARE_SCENE_EXTENSION_RENDERER(FRenderSettingSceneExtensionRenderer, FRenderSettingSceneExtension);
//
// public:
// 	FRenderSettingSceneExtensionRenderer(FRenderSettingSceneExtension& InSceneData) : SceneData(&InSceneData) {}
// 	
// 	virtual void UpdateSceneUniformBuffer(FRDGBuilder& GraphBuilder, FSceneUniformBuffer& SceneUniforms) override;
//
// private:
// 	FRenderSettingSceneExtension* SceneData = nullptr;
// };
//
// }
