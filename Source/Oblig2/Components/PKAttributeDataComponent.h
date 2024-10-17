#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PKAttributeDataComponent.generated.h"

// Declare Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUpSignature, int32, NewLevel);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OBLIG2_API UPKAttributeDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPKAttributeDataComponent();

	// Instancing Delegates
	FOnLevelUpSignature OnLevelUp;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void AddExperience(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	int32 GetLevel() const { return CharacterLevel; }

	/*
	 * Variables
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 CharacterLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 CharacterExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 Defense;

protected:
	void LevelUp();
};
