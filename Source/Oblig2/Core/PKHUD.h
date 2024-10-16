// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PKHUD.generated.h"

class UPKUserWidget;
/**
 *
 */
UCLASS()
class OBLIG2_API APKHUD : public AHUD
{
	GENERATED_BODY()

	public:  
    // Constructor  
    APKHUD();  

    virtual void BeginPlay() override;  

    // LevelUp Handler
    UFUNCTION()  
    void OnLevelUpHandler(int32 NewLevel);  

protected:  
    // Reference to the widget  
    UPROPERTY()  
    UPKUserWidget* UserWidget;  

    // Widget class to instantiate  
    UPROPERTY(EditDefaultsOnly, Category = "PKHUD")  
    TSubclassOf<UPKUserWidget> UserWidgetClass;  
};
