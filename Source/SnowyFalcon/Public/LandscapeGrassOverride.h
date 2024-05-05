// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LandscapeProxy.h"
#include "LandscapeGrassType.h"

#if WITH_EDITOR
#include "LevelEditor.h"
#endif

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
	
	TArray<TArray<FGrassVariety>> CachedDefaultGrassVarieties;

public:	
	ALandscapeGrassOverride();
	virtual void Tick(float DeltaTime) override;
	virtual void PostLoad() override;

protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void CacheLandscapeGrassTypes();
	void OverrideLandscapeGrassTypes();
	void ResetLandscapeGrassTypes();
	
#if WITH_EDITOR
	void OnEditorMapChanged(UWorld* World, EMapChangeType MapChangeType);
#endif
};
