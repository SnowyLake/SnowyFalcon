// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SnowyFalconDemo : ModuleRules
{
	public SnowyFalconDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
