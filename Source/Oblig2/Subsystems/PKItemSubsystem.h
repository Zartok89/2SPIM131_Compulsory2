//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Subsystems/WorldSubsystem.h"
//#include "PKItemSubsystem.generated.h"
//
//class UPKInventoryDataComponent;
///**
// *
// */
//UCLASS()
//class OBLIG2_API UPKItemSubsystem : public UTickableWorldSubsystem
//{
//	GENERATED_BODY()
//
//public:
//	// UWorldSubsystem overrides
//	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
//	virtual void Deinitialize() override;
//	virtual void Tick(float DeltaTime) override;
//	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }
//
//	// Make subsystem tickable
//	virtual bool IsTickable() const override { return true; }
//	virtual TStatId GetStatId() const override;
//
//	// Register Inventory Components
//	void RegisterComponent(UPKInventoryDataComponent* Component);
//	void UnregisterComponent(UPKInventoryDataComponent* Component);
//
//	/*
//	 * Member Variables
//	 */
//	TArray<AActor*> Actors;
//	TArray<UPKInventoryDataComponent*> InventoryDataComponents;
//	TArray<int32> PotionStacks;
//};
