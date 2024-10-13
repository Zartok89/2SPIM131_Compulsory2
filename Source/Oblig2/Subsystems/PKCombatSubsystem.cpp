// Fill out your copyright notice in the Description page of Project Settings.


#include "PKCombatSubsystem.h"

void UPKCombatSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UPKCombatSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UPKCombatSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TStatId UPKCombatSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UPKCombatSubsystem, STATGROUP_Tickables);
}
