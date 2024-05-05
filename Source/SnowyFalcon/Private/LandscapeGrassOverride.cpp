// Fill out your copyright notice in the Description page of Project Settings.


#include "LandscapeGrassOverride.h"

#include "LandscapeGrassType.h"
#include "LandscapeSubsystem.h"
#include "MaterialCachedData.h"

#if WITH_EDITOR
#include "LevelEditor.h"
#endif

ALandscapeGrassOverride::ALandscapeGrassOverride()
{
//	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;
}

void ALandscapeGrassOverride::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALandscapeGrassOverride::PostLoad()
{
	UE_LOG(LogTemp, Warning, TEXT("ALandscapeGrassOverride::PostLoad"));
	
	Super::PostLoad();
	
	CacheLandscapeGrassTypes();
	OverrideLandscapeGrassTypes();

#if WITH_EDITOR
	auto&& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditor.OnMapChanged().AddUObject(this, &ALandscapeGrassOverride::OnEditorMapChanged);
#endif
}

void ALandscapeGrassOverride::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("ALandscapeGrassOverride::EndPlay"));
	
	Super::EndPlay(EndPlayReason);

#if !WITH_EDITOR
	ResetLandscapeGrassTypes();
#endif
}

void ALandscapeGrassOverride::CacheLandscapeGrassTypes()
{
	if (!LandscapeProxy)
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("ALandscapeGrassOverride::CacheLandscapeGrassTypes"));

	CachedDefaultGrassVarieties.Empty();
	auto&& DefaultGrassTypes = LandscapeProxy->LandscapeMaterial->GetCachedExpressionData().GrassTypes;
	for (int i = 0; i < DefaultGrassTypes.Num(); ++i)
	{
		CachedDefaultGrassVarieties.Emplace(DefaultGrassTypes[i]->GrassVarieties);
	}
}

void ALandscapeGrassOverride::OverrideLandscapeGrassTypes()
{
	if (!LandscapeProxy)
	{
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("ALandscapeGrassOverride::OverrideLandscapeGrassTypes"));
	
	auto&& DefaultGrassTypes = LandscapeProxy->LandscapeMaterial->GetCachedExpressionData().GrassTypes;
	for (int i = 0; i < DefaultGrassTypes.Num(); ++i)
	{
		if (i < OverrideGrassTypes.Num() && OverrideGrassTypes[i] != nullptr)
		{
			DefaultGrassTypes[i]->GrassVarieties = OverrideGrassTypes[i]->GrassVarieties;
		}
	}
}

void ALandscapeGrassOverride::ResetLandscapeGrassTypes()
{
	if (!LandscapeProxy)
	{
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("ALandscapeGrassOverride::ResetLandscapeGrassTypes"));

	auto&& DefaultGrassTypes = LandscapeProxy->LandscapeMaterial->GetCachedExpressionData().GrassTypes;

	for (int i = 0; i < DefaultGrassTypes.Num(); ++i)
	{
		DefaultGrassTypes[i]->GrassVarieties = CachedDefaultGrassVarieties[i];
	}
}

#if WITH_EDITOR
void ALandscapeGrassOverride::OnEditorMapChanged(UWorld* World, EMapChangeType MapChangeType)
{
	if (MapChangeType == EMapChangeType::TearDownWorld)
	{
		ResetLandscapeGrassTypes();
		auto&& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditor.OnMapChanged().RemoveAll(this);
	}
}
#endif
