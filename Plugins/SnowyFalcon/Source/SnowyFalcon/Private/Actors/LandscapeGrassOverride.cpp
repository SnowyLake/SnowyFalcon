// Copyright (c) SnowyLake. All rights reserved.

#include "Actors/LandscapeGrassOverride.h"

#include "Utils/SnowyFalconSetting.h"

#include "LandscapeSubsystem.h"
#include "MaterialCachedData.h"

ALandscapeGrassOverride::ALandscapeGrassOverride()
{
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::Constructor"));
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	CachedLandscapeProxy = nullptr;
}

void ALandscapeGrassOverride::PostLoad()
{
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::PostLoad"));
	
	Super::PostLoad();
	
	CacheLandscapeGrassTypes();
	OverrideLandscapeGrassTypes();
}

void ALandscapeGrassOverride::BeginDestroy()
{
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::BeginDestroy"));
	
	Super::BeginDestroy();

	ResetLandscapeGrassTypes();
}

#if WITH_EDITOR
void ALandscapeGrassOverride::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::PostEditChangeProperty"));
	
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		FName PropertyName = PropertyChangedEvent.GetPropertyName();
	
		if (PropertyName == GET_MEMBER_NAME_CHECKED(ALandscapeGrassOverride, LandscapeProxy))
		{
			if (CachedLandscapeProxy)
			{
				EditorOverrideReset();
			}
			if (LandscapeProxy)
			{
				CacheLandscapeGrassTypes();
				EditorOverrideUpdate();
			}
		}
		if (PropertyName == GET_MEMBER_NAME_CHECKED(ALandscapeGrassOverride, OverrideGrassTypes))
		{
			EditorOverrideUpdate();
		}
	}
}

void ALandscapeGrassOverride::EditorOverrideUpdate()
{
	OverrideLandscapeGrassTypes();
	if (auto LandscapeSubsystem = GetWorld()->GetSubsystem<ULandscapeSubsystem>())
	{
		LandscapeSubsystem->RegenerateGrass(/*bInFlushGrass = */true, /*bInForceSync = */true);
	}
}

void ALandscapeGrassOverride::EditorOverrideReset()
{
	ResetLandscapeGrassTypes();
	if (auto LandscapeSubsystem = GetWorld()->GetSubsystem<ULandscapeSubsystem>())
	{
		LandscapeSubsystem->RegenerateGrass(/*bInFlushGrass = */true, /*bInForceSync = */true);
	}
}
#endif

void ALandscapeGrassOverride::CacheLandscapeGrassTypes()
{
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::CacheLandscapeGrassTypes"));
	
	CachedLandscapeProxy = LandscapeProxy;
	
	if (!LandscapeProxy)
	{
		return;
	}
	
	CachedDefaultGrassVarieties.Empty();
	auto&& DefaultGrassTypes = LandscapeProxy->LandscapeMaterial->GetCachedExpressionData().GrassTypes;
	for (int i = 0; i < DefaultGrassTypes.Num(); ++i)
	{
		CachedDefaultGrassVarieties.Add(DefaultGrassTypes[i]->GrassVarieties);
	}
}

void ALandscapeGrassOverride::OverrideLandscapeGrassTypes()
{
	if (!LandscapeProxy)
	{
		return;
	}
	
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::OverrideLandscapeGrassTypes"));
	
	auto&& GrassTypes = LandscapeProxy->LandscapeMaterial->GetCachedExpressionData().GrassTypes;
	for (int i = 0; i < GrassTypes.Num(); ++i)
	{
		if (i < OverrideGrassTypes.Num() && OverrideGrassTypes[i] != nullptr)
		{
			GrassTypes[i]->GrassVarieties = OverrideGrassTypes[i]->GrassVarieties;
		}else
		{
			GrassTypes[i]->GrassVarieties = CachedDefaultGrassVarieties[i];
		}
	}
}

void ALandscapeGrassOverride::ResetLandscapeGrassTypes()
{
	if (!CachedLandscapeProxy)
	{
		return;
	}
	
	UE_LOG(LogSnowyFalcon, Log, TEXT("ALandscapeGrassOverride::ResetLandscapeGrassTypes"));

	auto&& GrassTypes = CachedLandscapeProxy->LandscapeMaterial->GetCachedExpressionData().GrassTypes;

	for (int i = 0; i < GrassTypes.Num(); ++i)
	{
		if (i < CachedDefaultGrassVarieties.Num())
		{
			GrassTypes[i]->GrassVarieties = CachedDefaultGrassVarieties[i];
		}
	}
}