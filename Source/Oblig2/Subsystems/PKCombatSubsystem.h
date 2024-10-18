// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PKCombatSubsystem.generated.h"

class UPKAttributeDataComponent;
// Declare the attack event delegate  
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttackEvent, UPKAttributeDataComponent*, Attacker, UPKAttributeDataComponent*, Target);  

UCLASS()
class OBLIG2_API UPKCombatSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:

	// Event to broadcast when an attack occurs  
    FOnAttackEvent OnAttack;

	// UWorldSubsystem overrides
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }

	// Make subsystem tickable
	virtual bool IsTickable() const override { return true; }
	virtual TStatId GetStatId() const override;

	// Handle the attack event  
    UFUNCTION()  
    void HandleAttack(UPKAttributeDataComponent* Attacker, UPKAttributeDataComponent* Target);

	// Calculation of damage
    void CalculateDamage(UPKAttributeDataComponent* AttackerAttributes, UPKAttributeDataComponent* TargetAttributes);  
};
