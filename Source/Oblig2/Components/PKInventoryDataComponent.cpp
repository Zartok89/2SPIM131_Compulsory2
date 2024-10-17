#include "PKInventoryDataComponent.h"

UPKInventoryDataComponent::UPKInventoryDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	PotionStacks = 0;
}

void UPKInventoryDataComponent::PotionPickup()
{
}