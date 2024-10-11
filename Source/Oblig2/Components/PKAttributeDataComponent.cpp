#include "PKAttributeDataComponent.h"

UPKAttributeDataComponent::UPKAttributeDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

    // Initialize default values 
	Health.Emplace(100);
	MaxHealth.Emplace(100);
	AttackPower.Emplace(10);
	Defense.Emplace(4);
}