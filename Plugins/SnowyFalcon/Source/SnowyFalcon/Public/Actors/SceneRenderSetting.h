// Copyright (c) SnowyLake. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SceneRenderSetting.generated.h"

// UB Parameters
//-------------------------------------------
USTRUCT()
struct SNOWYFALCON_API FSceneRenderSettingParameterStruct
{
	GENERATED_USTRUCT_BODY()

	FSceneRenderSettingParameterStruct();

	UPROPERTY(EditAnywhere, Category = SceneRenderSetting)
	FLinearColor TestColor;
	UPROPERTY(EditAnywhere, Category = SceneRenderSetting)
	TObjectPtr<UTexture2D> TestTexture;
};

UCLASS()
class SNOWYFALCON_API ASceneRenderSetting : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = SceneRenderSetting)
	FSceneRenderSettingParameterStruct Parameters;

	static inline FSceneRenderSettingParameterStruct UBParameters{};

public:
	ASceneRenderSetting();
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override { return true; }
};
