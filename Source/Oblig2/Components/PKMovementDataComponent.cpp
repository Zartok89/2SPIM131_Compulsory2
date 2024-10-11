#include "PKMovementDataComponent.h"

// Sets default values for this component's properties
UPKMovementDataComponent::UPKMovementDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

    // Initialize default values 
    Velocity.Emplace(FVector::ZeroVector);  
    Acceleration.Emplace(FVector::ZeroVector);  
    MaxSpeed.Emplace(600.0f);
    Size = 1;
}