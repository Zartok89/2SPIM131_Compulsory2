#include "PKMovementDataComponent.h"

#include "Oblig2/Subsystems/PKMovementSubsystem.h"

// Sets default values for this component's properties
UPKMovementDataComponent::UPKMovementDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Initialize default values
	Velocity = FVector::ZeroVector;
	Acceleration = FVector::ZeroVector;
	MaxSpeed = 600.0f;
	Size = 1;
}

void UPKMovementDataComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register in the movement subsystem
	UPKMovementSubsystem* MovementSubsystem = GetWorld()->GetSubsystem<UPKMovementSubsystem>();
	if (MovementSubsystem)
	{
		MovementSubsystem->RegisterComponent(this);
	}
}

void UPKMovementDataComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// Unregister from the movement subsystem
	UPKMovementSubsystem* MovementSubsystem = GetWorld()->GetSubsystem<UPKMovementSubsystem>();
	if (MovementSubsystem)
	{
		MovementSubsystem->UnregisterComponent(this);
	}
}