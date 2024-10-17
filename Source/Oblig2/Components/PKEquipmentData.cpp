// Fill out your copyright notice in the Description page of Project Settings.

#include "PKEquipmentData.h"

UPKEquipmentData::UPKEquipmentData()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPKEquipmentData::BeginPlay()
{
	Super::BeginPlay();
}

void UPKEquipmentData::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPKEquipmentData::SwapWeapon(FName NewWeaponRowName)
{
	if (WeaponDataTable)
	{
		static const FString ContextString(TEXT("Weapon Data Context"));
		FPKItemWeaponTable* NewWeapon = WeaponDataTable->FindRow<FPKItemWeaponTable>(NewWeaponRowName, ContextString);
		if (NewWeapon)
		{
			if (CurrentWeapon.ItemName != "")
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Swapping weapon from %s to %s"), *CurrentWeapon.ItemName, *NewWeapon->ItemName));
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Equipping weapon: %s"), *NewWeapon->ItemName));
			}

			CurrentWeapon = *NewWeapon;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Weapon not found in DataTable!"));
		}
	}
}

void UPKEquipmentData::SwapArmor(FName NewArmorRowName)
{
	    if (ArmorDataTable)  
    {  
        static const FString ContextString(TEXT("Armor Data Context"));  
        FPKItemArmorTable* NewArmor = ArmorDataTable->FindRow<FPKItemArmorTable>(NewArmorRowName, ContextString);  
        if (NewArmor)  
        {  
            if (CurrentArmor.ItemName != "")  
            {  
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Swapping armor from %s to %s"), *CurrentArmor.ItemName, *NewArmor->ItemName));  
            }  
            else  
            {  
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Equipping armor: %s"), *NewArmor->ItemName));  
            }  

            CurrentArmor = *NewArmor;
        }  
        else  
        {  
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Armor not found in DataTable!"));  
        }  
    }  
}