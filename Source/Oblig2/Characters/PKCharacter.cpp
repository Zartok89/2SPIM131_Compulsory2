#include "PKCharacter.h"

// Sets default values
APKCharacter::APKCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APKCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APKCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APKCharacter::Die()
{
	HandleDeath();

	// Broadcasting that the character dies
	OnEnemyDeath.Broadcast(this);

	// Destroying the actor
	Destroy();
}

void APKCharacter::HandleDeath()
{
}