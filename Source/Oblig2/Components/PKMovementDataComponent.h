#pragma once

// Includes
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PKMovementDataComponent.generated.h"

// The MovementDataComponentClass
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OBLIG2_API UPKMovementDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPKMovementDataComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementData")
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementData")
	FVector Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementData")
	float MaxSpeed;

	int Size;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};