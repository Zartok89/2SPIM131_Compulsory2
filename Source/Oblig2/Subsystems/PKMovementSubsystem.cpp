// Fill out your copyright notice in the Description page of Project Settings.


#include "PKMovementSubsystem.h"

#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
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
                // Update velocity based on acceleration  
                MovementComponent->Velocity += MovementComponent->Acceleration * DeltaTime;  

                // Clamp velocity to MaxSpeed  
                MovementComponent->Velocity = MovementComponent->Velocity.GetClampedToMaxSize(MovementComponent->MaxSpeed);  

                // Update actor location  
                FVector NewLocation = Actor->GetActorLocation() + MovementComponent->Velocity * DeltaTime;  
                Actor->SetActorLocation(NewLocation);  
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
	// Find all actors with UMovementDataComponent
    for (TActorIterator<AActor> It(GetWorld()); It; ++It)
    {
        AActor* Actor = *It;
        if (Actor->FindComponentByClass<UPKMovementDataComponent>())
        {
            ActorsWithMovementComponent.Add(Actor);
        }
    }
}
