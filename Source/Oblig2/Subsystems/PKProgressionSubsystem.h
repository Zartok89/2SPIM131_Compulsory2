//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Oblig2/Components/PKAttributeDataComponent.h"
//#include "Oblig2/Components/PKIdentityDataComponent.h"
//#include "Subsystems/WorldSubsystem.h"
//#include "PKProgressionSubsystem.generated.h"
//
///**
// * 
// */
//UCLASS()
//class OBLIG2_API UPKProgressionSubsystem : public UWorldSubsystem
//{
//	GENERATED_BODY()
//
//	public:
//	// UWorldSubsystem overrides
//	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
//	virtual void Deinitialize() override;
//	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }
//
//	// Register Components
//	void RegisterIdentityDataComponent (UPKIdentityDataComponent* Component);
//	void UnregisterIdentityDataComponent(UPKIdentityDataComponent* Component);
//	void RegisterAttributeDataComponent (UPKAttributeDataComponent* Component);
//	void UnregisterAttributeDataComponent(UPKAttributeDataComponent* Component);
//
//
//private:
//	TArray<AActor*> Actors;
//	TArray<UPKIdentityDataComponent*> IdentityDataComponents;
//	TArray<UPKAttributeDataComponent*> AttributeDataComponents;
//	TArray<FString> CharacterNames;
//	TArray<FString> CharacterClasses;
//	TArray<int32> CharacterLevels;
//	TArray<int32> CharacterExps;
//
//};
