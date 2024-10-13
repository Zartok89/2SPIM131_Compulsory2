#include "PKIdentityDataComponent.h"

UPKIdentityDataComponent::UPKIdentityDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Initialize default values
	Name.Emplace("TheDude");
	Class.Emplace("NormalPerson");
	CharacterLevel.Emplace(1);
}