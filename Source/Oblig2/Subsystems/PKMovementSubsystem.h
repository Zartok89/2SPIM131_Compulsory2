#pragma once

#include "CoreMinimal.h"
#include "Oblig2/Components/PKMovementDataComponent.h"
#include "Subsystems/WorldSubsystem.h"
#include "PKMovementSubsystem.generated.h"

/**
 *
 */
UCLASS()
class OBLIG2_API UPKMovementSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	// UWorldSubsystem overrides
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }

	// Make subsystem tickable
	virtual bool IsTickable() const override { return true; }
	virtual TStatId GetStatId() const override;

	// Register Movement Components
	void RegisterComponent(UPKMovementDataComponent* Component);
	void UnregisterComponent(UPKMovementDataComponent* Component);

private:
	//TArray<TWeakObjectPtr<AActor>> Actors;
	TArray<AActor*> Actors;
	TArray<UPKMovementDataComponent*> MovementDataComponents;
	TArray<FVector> Velocities;
	TArray<FVector> Accelerations;
	TArray<float> MaxSpeeds;

	//void CollectActorsWithMovementComponent();
};
