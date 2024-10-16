#include "PKAttributeDataComponent.h"

#include "Oblig2/Subsystems/PKCombatSubsystem.h"
#include "Oblig2/Subsystems/PKProgressionSubsystem.h"

UPKAttributeDataComponent::UPKAttributeDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Initialize default values
	CharacterLevel = 1;
	CharacterExp = 0;
	Health = 100;
	MaxHealth = 100;
	AttackPower = 10;
	Defense = 4;
}

void UPKAttributeDataComponent::AddExperience(int32 Amount)
{
	if (CharacterExp >= 100)
	{
		LevelUp();
	}
}

void UPKAttributeDataComponent::LevelUp()
{
	CharacterLevel++;  
    CharacterExp = 0;
	OnLevelUp.Broadcast(CharacterLevel);
}


//// Unused code from earlier iteration
//
//	// Register in the Progression Subsystem
//	UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
//	if (ProgressionSubsystem)
//	{
//		ProgressionSubsystem->RegisterAttributeDataComponent(this);
//	}
//
//	// Register in the Combat Subsystem
//	UPKCombatSubsystem* CombatSubsystem = GetWorld()->GetSubsystem<UPKCombatSubsystem>();
//	if (CombatSubsystem)
//	{
//		//CombatSubsystem->RegisterAttributeDataComponent(this);
//
//	}
//	// Unregister from the Progression Subsystem
//	UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
//	if (ProgressionSubsystem)
//	{
//		ProgressionSubsystem->UnregisterAttributeDataComponent(this);
//	}
//
//	// Unregister from the Combat Subsystem
//	UPKCombatSubsystem* CombatSubsystem = GetWorld()->GetSubsystem<UPKCombatSubsystem>();
//	if (CombatSubsystem)
//	{
//		//CombatSubsystem->RegisterAttributeDataComponent(this);
//	}