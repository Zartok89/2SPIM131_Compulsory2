// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PKCharacter.h"
#include "PKCharacterPlayer.generated.h"

/**
 *
 */
UCLASS()
class OBLIG2_API APKCharacterPlayer : public APKCharacter
{
	GENERATED_BODY()

public:
	APKCharacterPlayer();

	// Declare Delegates
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUpSignature, APKCharacterPlayer*, Character);

	// Instancing the Delegate
	UPROPERTY(BlueprintAssignable, Category = "CharacterPlayerEvent")
	FOnLevelUpSignature OnLevelUp;

	void LevelUp();

	/*
	* Variables
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterEvent")
	UNiagaraComponent* NiagaraComponent;

protected:
	void HandleLevelUp();
};
