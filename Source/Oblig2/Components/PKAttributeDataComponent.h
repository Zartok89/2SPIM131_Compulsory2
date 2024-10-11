#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PKAttributeDataComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBLIG2_API UPKAttributeDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPKAttributeDataComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	TArray<int32> Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	TArray<int32> MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	TArray<int32> AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeData")
	TArray<int32> Defense;
};
