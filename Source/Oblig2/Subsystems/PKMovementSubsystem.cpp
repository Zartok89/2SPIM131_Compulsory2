// Fill out your copyright notice in the Description page of Project Settings.

#include "PKMovementSubsystem.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Oblig2/Components/PKMovementDataComponent.h"

void UPKMovementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UPKMovementSubsystem::Deinitialize()
{
	Actors.Empty();
	MovementDataComponents.Empty();
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
		MovementDataComponents[i]->Velocity = Velocities[i];
	}
}

TStatId UPKMovementSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UPKMovementSubsystem, STATGROUP_Tickables);
}

void UPKMovementSubsystem::RegisterComponent(UPKMovementDataComponent* Component)
{
	if (Component && Component->GetOwner())
	{
		Actors.AddUnique(Component->GetOwner());
		MovementDataComponents.AddUnique(Component);
		Velocities.Add(Component->Velocity);
		Accelerations.Add(Component->Acceleration);
		MaxSpeeds.Add(Component->MaxSpeed);
		UE_LOG(LogTemp, Warning, TEXT("Registered Actor: %s Movement Component"), *Component->GetOwner()->GetName());
	}
}

void UPKMovementSubsystem::UnregisterComponent(UPKMovementDataComponent* Component)
{
	int32 Index = MovementDataComponents.IndexOfByKey(Component);
	if (Index != INDEX_NONE)
	{
		Actors.RemoveAt(Index);
		MovementDataComponents.RemoveAt(Index);
		Velocities.RemoveAt(Index);
		Accelerations.RemoveAt(Index);
		MaxSpeeds.RemoveAt(Index);
		UE_LOG(LogTemp, Warning, TEXT("Unregistered Movement Component at index: %d"), Index);
	}
}

//void UPKMovementSubsystem::CollectActorsWithMovementComponent()
//{
//	// Getting the world
//	UWorld* World = GetWorld();
//
//	// Clear previous arrays before collecting
//	Actors.Empty();
//	MovementComponents.Empty();
//	Velocities.Empty();
//	Accelerations.Empty();
//	MaxSpeeds.Empty();
//
//	// Finding all objects in world which has UPKMovementDataComponent
//	for (TObjectIterator<UPKMovementDataComponent> It; It; ++It)
//	{
//		UPKMovementDataComponent* MovementDataComponent = *It;
//
//		if (MovementDataComponent && IsValid(MovementDataComponent))
//		{
//			AActor* Owner = MovementDataComponent->GetOwner();
//
//			if (Owner && IsValid(Owner))
//			{
//				// Adding all the different data each entity has into the MovementSubsystems TArrays to store them in sequence of the memory
//				if (Owner->GetWorld() == World)
//				{
//					// AddUnique ensure only one movement component exists on the Actor
//					Actors.AddUnique(Owner);
//
//					MovementComponents.Add(MovementDataComponent);
//					Velocities.Add(MovementDataComponent->Velocity);
//					Accelerations.Add(MovementDataComponent->Acceleration);
//					MaxSpeeds.Add(MovementDataComponent->MaxSpeed);
//
//					UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *Owner->GetName());
//				}
//			}
//		}
//	}
//
//	UE_LOG(LogTemp, Warning, TEXT("Total Actors with UPKMovementDataComponent: %d"), Actors.Num());
//}