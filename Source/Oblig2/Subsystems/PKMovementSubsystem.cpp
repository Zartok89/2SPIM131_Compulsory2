// Fill out your copyright notice in the Description page of Project Settings.

#include "PKMovementSubsystem.h"

#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Oblig2/Components/PKMovementDataComponent.h"

void UPKMovementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CollectActorsWithMovementComponent();
}

void UPKMovementSubsystem::Deinitialize()
{
	Actors.Empty();
	MovementComponents.Empty();
	Velocities.Empty();
	Accelerations.Empty();
	MaxSpeeds.Empty();
	Super::Deinitialize();
}

void UPKMovementSubsystem::Tick(float DeltaTime)
{
	const int32 NumActors = Actors.Num();

	for (int32 i = 0; i < NumActors; ++i)
	{
		// Update velocities
		Velocities[i] += Accelerations[i] * DeltaTime;

		// Clamp velocities
		Velocities[i] = Velocities[i].GetClampedToMaxSize(MaxSpeeds[i]);

		// Move the actor
		Actors[i]->AddActorWorldOffset(Velocities[i] * DeltaTime);

		// Synchronize back to the component
		MovementComponents[i]->Velocity = Velocities[i];
	}
}

TStatId UPKMovementSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UPKMovementSubsystem, STATGROUP_Tickables);
}

void UPKMovementSubsystem::CollectActorsWithMovementComponent()
{
	// Getting the world
	UWorld* World = GetWorld();

	// Clear previous arrays before collecting
	Actors.Empty();
	MovementComponents.Empty();
	Velocities.Empty();
	Accelerations.Empty();
	MaxSpeeds.Empty();

	// Finding all objects in world which has UPKMovementDataComponent
	for (TObjectIterator<UPKMovementDataComponent> It; It; ++It)
	{
		UPKMovementDataComponent* MovementComponent = *It;

		if (MovementComponent && IsValid(MovementComponent))
		{
			AActor* Owner = MovementComponent->GetOwner();

			if (Owner && IsValid(Owner))
			{
				// Adding all the different data each entity has into the MovementSubsystems TArrays to store them in sequence of the memory
				if (Owner->GetWorld() == World)
				{
					UPKMovementDataComponent* OwnerMovementComponent = Owner->FindComponentByClass<UPKMovementDataComponent>();

					Actors.AddUnique(Owner);
					MovementComponents.Add(OwnerMovementComponent);
					Velocities.Add(OwnerMovementComponent->Velocity);
					Accelerations.Add(OwnerMovementComponent->Acceleration);
					MaxSpeeds.Add(OwnerMovementComponent->MaxSpeed);
					UE_LOG(LogTemp, Log, TEXT("Found Actor: %s"), *Owner->GetName());
				}
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Total Actors with UPKMovementDataComponent: %d"), Actors.Num());
}