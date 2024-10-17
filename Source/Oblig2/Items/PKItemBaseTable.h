// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"
#include "PKItemBaseTable.generated.h"

USTRUCT(BlueprintType)
struct OBLIG2_API FPKItemBaseTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	int32 StackAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData")
	UStaticMesh* ItemModel;
};