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
	ActorsWithMovementComponent.Empty();
	Super::Deinitialize();
}

void UPKMovementSubsystem::Tick(float DeltaTime)
{
	// Process movement for each actor
	for (TWeakObjectPtr<AActor> ActorPtr : ActorsWithMovementComponent)
	{
		if (AActor* Actor = ActorPtr.Get())
		{
			UPKMovementDataComponent* MovementComponent = Actor->FindComponentByClass<UPKMovementDataComponent>();
			if (MovementComponent)
			{
				// Store each actors movement once per actor locally
				const int32 Size = MovementComponent->Size;
				TArray<FVector>& Velocities = MovementComponent->Velocity;
				TArray<FVector>& Accelerations = MovementComponent->Acceleration;
				TArray<float>& MaxSpeeds = MovementComponent->MaxSpeed;

				for (int i = 0; i < Size; ++i)
				{
					// Update velocity based on acceleration
					Velocities[i] += Accelerations[i] * DeltaTime;

					// Clamp velocity to MaxSpeed incase velocity is too high
					Velocities[i] = Velocities[i].GetClampedToMaxSize(MaxSpeeds[i]);

					// Update actor location
					Actor->AddActorWorldOffset(Velocities[i] * DeltaTime);
				}
			}
		}
	}
}

TStatId UPKMovementSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UMovementSubsystem, STATGROUP_Tickables);
}

void UPKMovementSubsystem::CollectActorsWithMovementComponent()
{
	// Getting the world
	UWorld* World = GetWorld();

	// Clear the array before collecting
	ActorsWithMovementComponent.Empty();

	// Iterate over all instances of UPKMovementDataComponent and adding them to the TArray ActorsWithMovementComponent
	for (TObjectIterator<UPKMovementDataComponent> It; It; ++It)
	{
		UPKMovementDataComponent* MovementComponent = *It;

		if (MovementComponent && IsValid(MovementComponent))
		{
			AActor* Owner = MovementComponent->GetOwner();
			if (Owner && IsValid(Owner))
			{
				if (Owner->GetWorld() == World)
				{
					ActorsWithMovementComponent.AddUnique(Owner);
					UE_LOG(LogTemp, Log, TEXT("Found Actor: %s"), *Owner->GetName());
				}
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Total Actors with UPKMovementDataComponent: %d"), ActorsWithMovementComponent.Num());
}