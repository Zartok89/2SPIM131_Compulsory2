//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "PKItemSubsystem.h"
//
//#include "Oblig2/Components/PKInventoryDataComponent.h"
//
//void UPKItemSubsystem::Initialize(FSubsystemCollectionBase& Collection)
//{
//	Super::Initialize(Collection);
//}
//
//void UPKItemSubsystem::Deinitialize()
//{
//	Super::Deinitialize();
//}
//
//void UPKItemSubsystem::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	const int32 NumActors = Actors.Num();
//
//	for (int32 i = 0; i < NumActors; ++i)
//	{
//		// Sync the latest PotionStacks Amount
//        int32 currentPotionStacks = InventoryDataComponents[i]->PotionStacks;
//
//        // Synchronize back to the component
//        InventoryDataComponents[i]->PotionStacks = PotionStacks[i];
//	}
//}
//
//TStatId UPKItemSubsystem::GetStatId() const
//{
//	RETURN_QUICK_DECLARE_CYCLE_STAT(UPKItemSubsystem, STATGROUP_Tickables);
//}
//
//void UPKItemSubsystem::RegisterComponent(UPKInventoryDataComponent* Component)
//{
//	// Registering the component
//	if (Component && Component->GetOwner())
//	{
//		Actors.AddUnique(Component->GetOwner());
//		InventoryDataComponents.AddUnique(Component);
//		PotionStacks.Add(Component->PotionStacks);
//		UE_LOG(LogTemp, Warning, TEXT("Registered Actor: %s Inventory Component"), *Component->GetOwner()->GetName());
//	}
//}
//
//void UPKItemSubsystem::UnregisterComponent(UPKInventoryDataComponent* Component)
//{
//	// Unregistering the component
//	int32 Index = InventoryDataComponents.IndexOfByKey(Component);
//	if (Index != INDEX_NONE)
//	{
//		Actors.RemoveAt(Index);
//		InventoryDataComponents.RemoveAt(Index);
//		PotionStacks.RemoveAt(Index);
//		UE_LOG(LogTemp, Warning, TEXT("Unregistered Inventory Component at index: %d"), Index);
//	}
//}