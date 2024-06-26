// Copyright (c) SnowyLake. All rights reserved.

#include "Utils/SnowyFalconSetting.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Misc/ConfigCacheIni.h"

DEFINE_LOG_CATEGORY(LogSnowyFalcon);

namespace SnowyFalcon
{
FSetting& FSetting::Get()
{
	static FSetting Instance{};
	return Instance;
}

FSetting::FSetting()
{
	UE_LOG(LogSnowyFalcon, Log, TEXT("Load SnowyFalcon Config..."));
	if (FString ConfigPath = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("SnowyFalcon"))->GetBaseDir(), TEXT("Config/SnowyFalconConfig.ini"));
		FPaths::FileExists(ConfigPath))
	{
		LoadConfig(FConfigCacheIni::NormalizeConfigIniPath(ConfigPath));
	}else
	{
		UE_LOG(LogSnowyFalcon, Log, TEXT("SnowyFalcon config file is not exist: %s"), *ConfigPath);
	}
	
}

void FSetting::LoadConfig(const FString& ConfigPath)
{
	FConfigFile ConfigFile;
	ConfigFile.Read(ConfigPath);
	
	// Shader Remapping
	//-----------------------------------
	FString Section = TEXT("ShaderRemapping");
	GetValueBool(ConfigFile, *Section, TEXT("ShaderSourceRemapping"), bShaderSourceRemapping);
	GetValueString(ConfigFile, *Section, TEXT("ShaderSourceRemappingDirectory"), ShaderSourceRemappingDirectory);
}



void FSetting::GetValueBool(const FConfigFile& ConfigFile, const TCHAR* Section, const TCHAR* Key, bool& Value)
{
	if (bool DummyValue; ConfigFile.GetBool(Section, Key, DummyValue))
	{
		ConfigFile.GetBool(Section, Key, Value);
		UE_LOG(LogSnowyFalcon, Log, TEXT("Setting.%s.%s: %d"), Section, Key, Value);
	}
}

void FSetting::GetValueString(const FConfigFile& ConfigFile, const TCHAR* Section, const TCHAR* Key, FString& Value)
{
	if (FString DummyValue; ConfigFile.GetString(Section, Key, DummyValue))
	{
		ConfigFile.GetString(Section, Key, Value);
		UE_LOG(LogSnowyFalcon, Log, TEXT("Setting.%s.%s: %s"), Section, Key, *Value);
	}
}

void FSetting::GetValueArray(const FConfigFile& ConfigFile, const TCHAR* Section, const TCHAR* Key, TArray<FString>& Value)
{
	if (TArray<FString> DummyValue; ConfigFile.GetArray(Section, Key, DummyValue) > 0)
	{
		ConfigFile.GetArray(Section, Key, Value);
		UE_LOG(LogSnowyFalcon, Log, TEXT("Setting.%s.%s:"), Section, Key);
		for (const auto& Str : Value)
		{
			UE_LOG(LogSnowyFalcon, Log, TEXT("\t%s"), *Str);
		}
	}
}

}