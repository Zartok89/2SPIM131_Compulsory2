#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PKAttributeDataComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OBLIG2_API UPKAttributeDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPKAttributeDataComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 CharacterLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 CharacterExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	int32 Defense;

	protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
