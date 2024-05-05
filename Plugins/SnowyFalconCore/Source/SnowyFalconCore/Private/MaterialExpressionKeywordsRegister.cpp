// Fill out your copyright notice in the Description page of Project Settings.

#include "MaterialExpressionKeywordsRegister.h"

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

#define LOCTEXT_NAMESPACE "MaterialExpressionKeywordsRegister"

UMaterialExpressionKeywordsRegister::UMaterialExpressionKeywordsRegister(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		FText NAME_SnowyFalcon;
		FConstructorStatics()
			: NAME_SnowyFalcon(LOCTEXT("SnowyFalcon Core", "SnowyFalcon Core"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics{};
#endif // WITH_EDITORONLY_DATA

#if WITH_EDITORONLY_DATA
	MenuCategories.Add(ConstructorStatics.NAME_SnowyFalcon);
#endif

	InternalCustomExpression = CreateDefaultSubobject<UMaterialExpressionCustom>(TEXT("InternalCustomExpression"));
	
#if WITH_EDITORONLY_DATA
	bCollapsed = true;
#endif // WITH_EDITORONLY_DATA
}

int32 UMaterialExpressionKeywordsRegister::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
	TArray<int32> CompiledInputs;
	for (int32 i = 0; i < InternalCustomExpression->Inputs.Num(); i++)
	{
		if (InternalCustomExpression->Inputs[i].InputName.IsNone())
		{
			CompiledInputs.Add(INDEX_NONE);
		}
	}

	InternalCustomExpression->AdditionalDefines.Empty();
	
	for (int32 i = 0; i < Keywords.Num(); i++)
	{
		int32 V = INDEX_NONE;
		if (KeywordsInput[i].GetTracedInput().Expression)
		{
			V = KeywordsInput[i].Compile(Compiler);
		}
		bool bValue = false;
		if (V != INDEX_NONE)
		{
			bool bSucceeded;
			bValue = Compiler->GetStaticBoolValue(V, bSucceeded);
			if (!bSucceeded)
			{
				return INDEX_NONE;
			}
		}

		InternalCustomExpression->AdditionalDefines.Add({Keywords[i], bValue ? TEXT("1") : TEXT("0")});
	}
	
	return Compiler->CustomExpression(InternalCustomExpression, OutputIndex, CompiledInputs);
}

TArrayView<FExpressionInput*> UMaterialExpressionKeywordsRegister::GetInputsView()
{
	KeywordsInput.SetNum(Keywords.Num());
	
	CachedInputs.Empty();
	CachedInputs.Reserve(Keywords.Num());
	for (int32 i = 0; i < Keywords.Num(); i++)
	{
		CachedInputs.Add(&KeywordsInput[i]);
	}
	return CachedInputs;
}

FExpressionInput* UMaterialExpressionKeywordsRegister::GetInput(int32 InputIndex)
{
	if (InputIndex < KeywordsInput.Num())
	{
		return &KeywordsInput[InputIndex];
	}
	return nullptr;
}

FName UMaterialExpressionKeywordsRegister::GetInputName(int32 InputIndex) const
{
	if (InputIndex < KeywordsInput.Num())
	{
		return FName(*Keywords[InputIndex]);
	}
	return NAME_None;
}