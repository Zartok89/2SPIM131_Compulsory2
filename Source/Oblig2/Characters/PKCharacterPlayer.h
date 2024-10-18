// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PKCharacter.h"
#include "PKCharacterPlayer.generated.h"

class UPKAttributeDataComponent;
class UPKEquipmentData;

/**
 *
 */
UCLASS()
class OBLIG2_API APKCharacterPlayer : public APKCharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	APKCharacterPlayer();

	// Handler function for delegate signatures
	UFUNCTION()
	void OnLevelUpHandler(int32 NewLevel);

	/*
	* Variables
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterEvent")
	UNiagaraComponent* NiagaraLevelUpComponent;

	UFUNCTION(BlueprintCallable, Category = "Combat")  
   void PerformAttack(UPKAttributeDataComponent* AttackerAttributes, UPKAttributeDataComponent* TargetAttributes);  

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")  
    UPKAttributeDataComponent* AttributeDataComponent;  

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")  
    UPKEquipmentData* EquipmentDataComponent;  

protected:
	void LevelUp();
};
