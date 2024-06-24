// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SceneRenderSetting.generated.h"

UCLASS()
class SNOWYFALCON_API ASceneRenderSetting : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = SceneRenderSetting)
	FLinearColor TestColor = FLinearColor::White;
	
	UPROPERTY(EditAnywhere, Category = SceneRenderSetting)
	TObjectPtr<UTexture2D> TestTexture = nullptr;

	
	// UB Parameters
	//-------------------------------------------
	struct FParameters
	{
		FLinearColor TestColor = FLinearColor::White;
		UTexture2D* TestTexture = nullptr;
	};
	static inline FParameters Parameters{};

public:
	ASceneRenderSetting();
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override { return true; }
};
