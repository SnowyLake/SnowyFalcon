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
	
	UPROPERTY()
	FExpressionInput EnbaleToonLit;

public:
#if WITH_EDITOR
	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override;
#endif
	
	virtual int32 GetNumOutputs() const override;
	virtual FString GetFunctionName() const override;
	virtual FString GetDisplayName() const override;
};
