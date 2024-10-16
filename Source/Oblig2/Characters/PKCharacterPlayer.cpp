// Fill out your copyright notice in the Description page of Project Settings.

#include "PKCharacterPlayer.h"
#include "Oblig2/Components/PKAttributeDataComponent.h"

APKCharacterPlayer::APKCharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creating and setting up the Niagara Component
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("LevelUpEffect");
	NiagaraComponent->SetupAttachment(RootComponent);
	NiagaraComponent->SetAutoActivate(false);
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
}

void APKCharacterPlayer::OnLevelUpHandler(int32 NewLevel)
{
	LevelUp();

	//if (YourUIWidget)  
 //   {  
 //       YourUIWidget->UpdateLevelDisplay(NewLevel);  
 //   }  
}

void APKCharacterPlayer::LevelUp()
{
	NiagaraComponent->Activate(true);
}
