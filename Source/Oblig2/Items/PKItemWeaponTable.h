// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PKItemBaseTable.h"
#include "PKItemWeaponTable.generated.h"

USTRUCT(BlueprintType)
struct OBLIG2_API FPKItemWeaponTable : public FPKItemBaseTable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	int32 AttackPower;
};
