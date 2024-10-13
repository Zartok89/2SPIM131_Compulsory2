#include "PKIdentityDataComponent.h"

#include "Oblig2/Subsystems/PKProgressionSubsystem.h"

UPKIdentityDataComponent::UPKIdentityDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Initialize default values
	CharacterName = "TheDude";
	CharacterClass = "NormalPerson";
}

void UPKIdentityDataComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register in the Progression Subsystem
	UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
	if (ProgressionSubsystem)
	{
		ProgressionSubsystem->RegisterIdentityDataComponent(this);
	}
}

void UPKIdentityDataComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Unregister from the Progression Subsystem
	UPKProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetSubsystem<UPKProgressionSubsystem>();
	if (ProgressionSubsystem)
	{
		ProgressionSubsystem->UnregisterIdentityDataComponent(this);
	}
}