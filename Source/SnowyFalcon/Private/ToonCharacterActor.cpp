// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonCharacterActor.h"

AToonCharacterActor::AToonCharacterActor() : ASkeletalMeshActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AToonCharacterActor::BeginPlay()
{
	Super::BeginPlay();
}

void AToonCharacterActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
