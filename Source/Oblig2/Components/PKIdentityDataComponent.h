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
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IdentityData")
	FString CharacterClass;

	protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
