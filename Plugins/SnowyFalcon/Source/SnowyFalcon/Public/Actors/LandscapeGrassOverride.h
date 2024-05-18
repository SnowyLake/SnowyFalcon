// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LandscapeProxy.h"
#include "LandscapeGrassType.h"

#include "LandscapeGrassOverride.generated.h"

UCLASS()
class SNOWYFALCON_API ALandscapeGrassOverride : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, Category = LandscapeGrassOverride)
	TObjectPtr<ALandscapeProxy> LandscapeProxy;
	
	UPROPERTY(EditAnywhere, Category = LandscapeGrassOverride)
	TArray<TObjectPtr<ULandscapeGrassType>> OverrideGrassTypes;

private:
	UPROPERTY(VisibleAnywhere, Category = LandscapeGrassOverride)
	TObjectPtr<USceneComponent> SceneComponent;

	UPROPERTY()
	TObjectPtr<ALandscapeProxy> CachedLandscapeProxy;
	TArray<TArray<FGrassVariety>> CachedDefaultGrassVarieties;

public:	
	ALandscapeGrassOverride();
	virtual void PostLoad() override;
	virtual void BeginDestroy() override;
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	
	UFUNCTION(CallInEditor, Category = "LandscapeGrassOverride")
	void EditorOverrideUpdate();
	
	UFUNCTION(CallInEditor, Category = "LandscapeGrassOverride")
	void EditorOverrideReset();
#endif
	
private:
	void CacheLandscapeGrassTypes();
	void OverrideLandscapeGrassTypes();
	void ResetLandscapeGrassTypes();
};