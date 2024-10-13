// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"  
#include "NiagaraFunctionLibrary.h"
#include "PKCharacter.generated.h"

UCLASS()
class OBLIG2_API APKCharacter : public AActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	// Declare Delegates
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterDeathSignature, APKCharacter*, Character);

	// Sets default values for this actor's properties
	APKCharacter();

	virtual void Tick(float DeltaTime) override;

	// Instancing the Delegate
	UPROPERTY(BlueprintAssignable, Category = "CharacterEvent")
	FOnCharacterDeathSignature OnEnemyDeath;

	void Die();

protected:
	void HandleDeath();
};
