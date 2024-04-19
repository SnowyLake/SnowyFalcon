// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"

#include "ToonCharacterActor.generated.h"

UCLASS()
class SNOWYFALCON_API AToonCharacterActor : public ASkeletalMeshActor
{
	GENERATED_BODY()

public:	
	AToonCharacterActor();

protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaSeconds) override;
};
