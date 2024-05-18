// Fill out your copyright notice in the Description page of Project Settings.

#include "MaterialExpressions/MaterialExpressionToonLitOutput.h"

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
			: NAME_SnowyFalconShadingModel(LOCTEXT("SnowyFalcon", "SnowyFalcon"))
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
	
	if (!Enable)
	{
		return CodeInput;
	}

	switch (OutputIndex)
	{
	case 0:
		CodeInput = TestColor.IsConnected() ? TestColor.Compile(Compiler) : Compiler->Constant3(1.0f, 1.0f, 1.0f);
		break;
		
	case OutputNum - 1:
		CodeInput = Keywords.IsConnected() ? Keywords.Compile(Compiler) : Compiler->Constant(1.0f);
		break;
		
	default:
		break;
	}

	return Compiler->CustomOutput(this, OutputIndex, CodeInput);
}
#endif

#undef LOCTEXT_NAMESPACE