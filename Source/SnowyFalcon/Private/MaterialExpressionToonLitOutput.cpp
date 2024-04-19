// Fill out your copyright notice in the Description page of Project Settings.

#include "MaterialExpressionToonLitOutput.h"

#include "Engine/Engine.h"
#include "MaterialShared.h"
#include "Materials/MaterialExpression.h"
#include "Materials/Material.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceConstant.h"
#include "MaterialCompiler.h"
#if WITH_EDITOR
#include "MaterialGraph/MaterialGraphNode_Comment.h"
#include "MaterialGraph/MaterialGraphNode.h"
#include "MaterialGraph/MaterialGraphSchema.h"
#endif //WITH_EDITOR

#define LOCTEXT_NAMESPACE "MaterialExpressionToonLitOutput"

UMaterialExpressionToonLitOutput::UMaterialExpressionToonLitOutput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		FText NAME_SnowyFalconShadingModel;
		FConstructorStatics()
			: NAME_SnowyFalconShadingModel(LOCTEXT("SnowyFalcon ShadingModel", "SnowyFalcon ShadingModel"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics{};

	MenuCategories.Add(ConstructorStatics.NAME_SnowyFalconShadingModel);

	bCollapsed = true;

	// No outputs
	Outputs.Reset();
#endif
}

#if WITH_EDITOR
int32 UMaterialExpressionToonLitOutput::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
	int32 CodeInput = INDEX_NONE;

	switch (OutputIndex)
	{
	case 0:
		CodeInput = EnbaleToonLit.IsConnected() ? EnbaleToonLit.Compile(Compiler) : Compiler->StaticBool(false);
		break;
	
	default:
		CompilerError(Compiler, TEXT("Input missing!"));
		break;
	}

	return Compiler->CustomOutput(this, OutputIndex, CodeInput);
}

void UMaterialExpressionToonLitOutput::GetCaption(TArray<FString>& OutCaptions) const
{
	OutCaptions.Add(FString(TEXT("SnowyFalcon ToonLit Output")));
}
#endif

int32 UMaterialExpressionToonLitOutput::GetNumOutputs() const
{
	return 1;
}

FString UMaterialExpressionToonLitOutput::GetFunctionName() const
{
	return TEXT("GetSnowyFalconToonLitOutput");
}

FString UMaterialExpressionToonLitOutput::GetDisplayName() const
{
	return TEXT("SnowyFalcon ToonLit"); 
}

#undef LOCTEXT_NAMESPACE