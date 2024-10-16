//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "PKProgressionSubsystem.h"
//
//void UPKProgressionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
//{
//	Super::Initialize(Collection);
//}
//
//void UPKProgressionSubsystem::Deinitialize()
//{
//	Actors.Empty();
//	IdentityDataComponents.Empty();
//	AttributeDataComponents.Empty();
//	CharacterNames.Empty();
//	CharacterClasses.Empty();
//	CharacterLevels.Empty();
//	CharacterExps.Empty();
//	Super::Deinitialize();
//}
//
//void UPKProgressionSubsystem::RegisterIdentityDataComponent(UPKIdentityDataComponent* Component)
//{
//		if (Component && Component->GetOwner())
//	{
//		Actors.AddUnique(Component->GetOwner());
//		IdentityDataComponents.AddUnique(Component);
//		CharacterNames.Add(Component->CharacterName);
//		CharacterClasses.Add(Component->CharacterClass);
//		UE_LOG(LogTemp, Warning, TEXT("Registered Actor: %s Identity Component"), *Component->GetOwner()->GetName());
//	}
//}
//
//void UPKProgressionSubsystem::UnregisterIdentityDataComponent(UPKIdentityDataComponent* Component)
//{
//	int32 Index = IdentityDataComponents.IndexOfByKey(Component);
//	if (Index != INDEX_NONE)
//	{
//		Actors.RemoveAt(Index);
//		IdentityDataComponents.RemoveAt(Index);
//		CharacterNames.RemoveAt(Index);
//		CharacterClasses.RemoveAt(Index);
//		UE_LOG(LogTemp, Warning, TEXT("Unregistered Identity Component at index: %d"), Index);
//	}
//}
//
//void UPKProgressionSubsystem::RegisterAttributeDataComponent(UPKAttributeDataComponent* Component)
//{
//	if (Component && Component->GetOwner())
//	{
//		Actors.AddUnique(Component->GetOwner());
//		AttributeDataComponents.AddUnique(Component);
//		CharacterLevels.Add(Component->CharacterLevel);
//		CharacterExps.Add(Component->CharacterExp);
//		UE_LOG(LogTemp, Warning, TEXT("Registered Actor: %s Progression Component"), *Component->GetOwner()->GetName());
//	}
//}
//
//void UPKProgressionSubsystem::UnregisterAttributeDataComponent(UPKAttributeDataComponent* Component)
//{
//	int32 Index = AttributeDataComponents.IndexOfByKey(Component);
//	if (Index != INDEX_NONE)
//	{
//		Actors.RemoveAt(Index);
//		AttributeDataComponents.RemoveAt(Index);
//		CharacterLevels.RemoveAt(Index);
//		CharacterExps.RemoveAt(Index);
//		UE_LOG(LogTemp, Warning, TEXT("Unregistered Progression Component at index: %d"), Index);
//	}
//}