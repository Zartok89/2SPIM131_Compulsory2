// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PKItemBaseTable.h"
#include "PKItemArmorTable.generated.h"

USTRUCT(BlueprintType)
struct OBLIG2_API FPKItemArmorTable : public FPKItemBaseTable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	int32 Armor;
};
