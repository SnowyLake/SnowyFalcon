// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MaterialExpressionIO.h"
#include "Materials/MaterialExpressionCustom.h"
#include "MaterialExpressionKeywordsRegister.generated.h"

UCLASS()
class SNOWYFALCON_API UMaterialExpressionKeywordsRegister : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, Category=MaterialExpressionKeywordsRegister)
	TArray<FName> Keywords;
	
	UPROPERTY()
	TArray<FExpressionInput> KeywordsInput;
	UPROPERTY()
	TObjectPtr<UMaterialExpressionCustom> InternalCustomExpression;
	
#if WITH_EDITOR
	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override { OutCaptions.Add(FString(TEXT("SnowyFalcon Keywords Register"))); }
	virtual FText GetCreationName() const override { return FText::FromString(TEXT("Keywords Register")); }
	virtual TArrayView<FExpressionInput*> GetInputsView() override;
	virtual FExpressionInput* GetInput(int32 InputIndex) override;
	virtual FName GetInputName(int32 InputIndex) const override;
	virtual uint32 GetInputType(int32 InputIndex) override { return MCT_StaticBool; }
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif 
};