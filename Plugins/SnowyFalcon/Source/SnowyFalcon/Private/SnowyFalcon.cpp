#include "SnowyFalcon.h"

#include "Utils/ShaderUtils.h"

#define LOCTEXT_NAMESPACE "FSnowyFalconModule"

void FSnowyFalconModule::StartupModule()
{
	SnowyFalcon::FShaderUtils::ShaderSourceDirectoryRemapping();
}

void FSnowyFalconModule::ShutdownModule()
{
	SnowyFalcon::FShaderUtils::ShaderSourceDirectoryReset();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSnowyFalconModule, SnowyFalcon)