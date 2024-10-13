// Fill out your copyright notice in the Description page of Project Settings.

#include "PKCharacterPlayer.h"

APKCharacterPlayer::APKCharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creating and setting up the Niagara Component
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("LevelUpEffect");
	NiagaraComponent->SetupAttachment(RootComponent);
	NiagaraComponent->SetAutoActivate(false);
}

void APKCharacterPlayer::LevelUp()
{
	HandleLevelUp();

	OnLevelUp.Broadcast(this);
}

void APKCharacterPlayer::HandleLevelUp()
{
	NiagaraComponent->Activate(true);
}