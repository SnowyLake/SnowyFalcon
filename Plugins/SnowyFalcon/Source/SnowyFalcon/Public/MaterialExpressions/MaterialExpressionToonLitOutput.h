// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MaterialExpressionIO.h"
#include "Materials/MaterialExpressionCustomOutput.h"
#include "MaterialExpressionToonLitOutput.generated.h"

UCLASS()
class SNOWYFALCON_API UMaterialExpressionToonLitOutput : public UMaterialExpressionCustomOutput
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category=MaterialExpressionToonLitOutput)
	uint32 Enable : 1 = 1;
	
	UPROPERTY()
	FExpressionInput TestColor;

	UPROPERTY()
	FExpressionInput Keywords;
	
	inline static constexpr int32 OutputNum = 2;

public:
#if WITH_EDITOR
	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override { OutCaptions.Add(FString(TEXT("SnowyFalcon ToonLit Output"))); }
	virtual bool NeedsCustomOutputDefines() override { return Enable ? true : false; }
#endif
	
	virtual int32 GetNumOutputs() const override { return OutputNum; }
	virtual FString GetFunctionName() const override { return TEXT("GetSnowyFalconToonLitOutput"); }
	virtual FString GetDisplayName() const override { return TEXT("SnowyFalcon ToonLit"); }
};
