#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"  
#include "Oblig2/Items/PKItemWeaponTable.h"
#include "Oblig2/Items/PKItemArmorTable.h"
#include "PKEquipmentData.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OBLIG2_API UPKEquipmentData : public UActorComponent
{
	GENERATED_BODY()

public:
	UPKEquipmentData();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Function to swap weapon
    UFUNCTION(BlueprintCallable, Category = "Equipment")  
    void SwapWeapon(FName NewWeaponRowName);  

    // Function to swap armor  
    UFUNCTION(BlueprintCallable, Category = "Equipment")  
    void SwapArmor(FName NewArmorRowName);  

	/*
	* Variables
	*/

	// Data Tables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentData")
	UDataTable* WeaponDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentData")
	UDataTable* ArmorDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentData")
	UDataTable* SupportDataTable;
	
    // Currently equipped items  
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")  
    FPKItemWeaponTable CurrentWeapon;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")  
    FPKItemArmorTable CurrentArmor;  
};