// Fill out your copyright notice in the Description page of Project Settings.

#include "PKCombatSubsystem.h"
#include "Oblig2/Components/PKAttributeDataComponent.h"

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

void UPKCombatSubsystem::HandleAttack(UPKAttributeDataComponent* Attacker, UPKAttributeDataComponent* Target)
{
	CalculateDamage(Attacker, Target);
}

void UPKCombatSubsystem::CalculateDamage(UPKAttributeDataComponent* AttackerAttributes, UPKAttributeDataComponent* TargetAttributes)
{
	// Getting Attack Power and Target Defense
	int32 AttackPower = AttackerAttributes->AttackPower;
	int32 Defense = TargetAttributes->Defense;

	// Calculate damage
	int32 DamageDealt = FMath::Max(AttackPower - Defense, 0);

	// Subtract from target Health
	TargetAttributes->Health -= DamageDealt;

	// Log damage dealt for debugging
	FString LogMessage = FString::Printf(TEXT("%s dealt %d damage to %s!"),
		*AttackerAttributes->GetOwner()->GetName(), DamageDealt, *TargetAttributes->GetOwner()->GetName());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *LogMessage);
}