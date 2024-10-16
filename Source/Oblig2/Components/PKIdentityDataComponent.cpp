#include "PKIdentityDataComponent.h"

#include "Oblig2/Subsystems/PKProgressionSubsystem.h"

UPKIdentityDataComponent::UPKIdentityDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Initialize default values
	CharacterName = "TheDude";
	CharacterClass = "NormalPerson";
}

// Unused code from earlier iteration

	//// Register in the Progression Subsystem
	//UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
	//if (ProgressionSubsystem)
	//{
	//	ProgressionSubsystem->RegisterIdentityDataComponent(this);
	//}

	//// Unregister from the Progression Subsystem
	//UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
	//if (ProgressionSubsystem)
	//{
	//	ProgressionSubsystem->UnregisterIdentityDataComponent(this);
	//}