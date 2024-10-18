// Fill out your copyright notice in the Description page of Project Settings.

#include "PKCharacterPlayer.h"
#include "Oblig2/Components/PKAttributeDataComponent.h"
#include "Oblig2/Subsystems/PKCombatSubsystem.h"

APKCharacterPlayer::APKCharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creating and setting up the Niagara Component
	NiagaraLevelUpComponent = CreateDefaultSubobject<UNiagaraComponent>("LevelUpEffect");
	NiagaraLevelUpComponent->SetupAttachment(RootComponent);
	NiagaraLevelUpComponent->SetAutoActivate(false);
}

void APKCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Getting the attribute data component from the actor
	UPKAttributeDataComponent* AttributeComponent = FindComponentByClass<UPKAttributeDataComponent>();
	if (AttributeComponent)
	{
		// Bind the OnLevelUpHandler function to the OnLevelUp delegate
		AttributeComponent->OnLevelUp.AddDynamic(this, &APKCharacterPlayer::OnLevelUpHandler);
	}

	UPKCombatSubsystem* CombatSubsystem = GetWorld()->GetSubsystem<UPKCombatSubsystem>();
	if (CombatSubsystem && AttributeDataComponent && EquipmentDataComponent)
	{
		CombatSubsystem->OnAttack.AddDynamic(this, &APKCharacterPlayer::PerformAttack);
	}
}

void APKCharacterPlayer::OnLevelUpHandler(int32 NewLevel)
{
	LevelUp();

	//if (YourUIWidget)
 //   {
 //       YourUIWidget->UpdateLevelDisplay(NewLevel);
 //   }
}

void APKCharacterPlayer::PerformAttack(UPKAttributeDataComponent* AttackerAttributes, UPKAttributeDataComponent* TargetAttributes)
{
	UPKCombatSubsystem* CombatSubsystem = GetWorld()->GetSubsystem<UPKCombatSubsystem>();
	if (CombatSubsystem)
	{
		CombatSubsystem->OnAttack.Broadcast(AttackerAttributes, TargetAttributes); 
	}
}

void APKCharacterPlayer::LevelUp()
{
	NiagaraLevelUpComponent->Activate(true);
}