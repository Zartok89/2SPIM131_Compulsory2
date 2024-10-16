// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PKUserWidget.generated.h"

/**
 *
 */
UCLASS()
class OBLIG2_API UPKUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Function to update the level display
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "UI")
	void UpdateLevelDisplay(int32 NewLevel);
};
