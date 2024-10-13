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

void UPKAttributeDataComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register in the Progression Subsystem
	UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
	if (ProgressionSubsystem)
	{
		ProgressionSubsystem->RegisterAttributeDataComponent(this);
	}

	// Register in the Combat Subsystem
	UPKCombatSubsystem* CombatSubsystem = GetWorld()->GetSubsystem<UPKCombatSubsystem>();
	if (CombatSubsystem)
	{
		//CombatSubsystem->RegisterAttributeDataComponent(this);
	}
}

void UPKAttributeDataComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Unregister from the Progression Subsystem
	UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
	if (ProgressionSubsystem)
	{
		ProgressionSubsystem->UnregisterAttributeDataComponent(this);
	}

	// Unregister from the Combat Subsystem
	UPKCombatSubsystem* CombatSubsystem = GetWorld()->GetSubsystem<UPKCombatSubsystem>();
	if (CombatSubsystem)
	{
		//CombatSubsystem->RegisterAttributeDataComponent(this);
	}
}
