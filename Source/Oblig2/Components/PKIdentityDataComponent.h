#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PKIdentityDataComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OBLIG2_API UPKIdentityDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPKIdentityDataComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IdentityData")
	TArray<FString> Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IdentityData")
	TArray<FString> Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IdentityData")
	TArray<int32> CharacterLevel;
};
