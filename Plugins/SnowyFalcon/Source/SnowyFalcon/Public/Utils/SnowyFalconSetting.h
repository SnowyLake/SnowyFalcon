// Copyright (c) SnowyLake. All rights reserved.

#pragma once

#include "CoreMinimal.h"

SNOWYFALCON_API DECLARE_LOG_CATEGORY_EXTERN(LogSnowyFalcon, Verbose, All);

namespace SnowyFalcon
{
class SNOWYFALCON_API FSetting
{
public:
	static FSetting& Get();

public:
	// ----------- Configs -----------
	// Shader Remapping
	bool bShaderSourceRemapping;
	FString ShaderSourceRemappingDirectory;

private:
	FSetting();
	~FSetting() = default;
	FSetting(const FSetting&) = delete;
	FSetting& operator=(const FSetting&) = delete;
	FSetting(FSetting&&) = delete;
	FSetting& operator=(FSetting&&) = delete;

private:
	void LoadConfig(const FString& ConfigPath);

	static void GetValueBool(const FConfigFile& ConfigFile, const TCHAR* Section, const TCHAR* Key, bool& Value);
	static void GetValueString(const FConfigFile& ConfigFile, const TCHAR* Section, const TCHAR* Key, FString& Value);
	static void GetValueArray(const FConfigFile& ConfigFile, const TCHAR* Section, const TCHAR* Key, TArray<FString>& Value);
};
}

