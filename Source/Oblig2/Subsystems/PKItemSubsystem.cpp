// Fill out your copyright notice in the Description page of Project Settings.


#include "PKItemSubsystem.h"

void UPKItemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UPKItemSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UPKItemSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TStatId UPKItemSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UPKItemSubsystem, STATGROUP_Tickables);
}
