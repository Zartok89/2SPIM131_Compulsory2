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
	TArray<FVector> Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementData")
	TArray<FVector> Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementData")
	TArray<float> MaxSpeed;

	int Size;
};

//USTRUCT()
//struct FPKMovementDataComponentStruct
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere, Category = "MovementData")
//	TArray<FVector> Velocity;
//
//	UPROPERTY(EditAnywhere, Category = "MovementData")
//	TArray<FVector> Acceleration;
//
//	UPROPERTY(EditAnywhere, Category = "MovementData")
//	TArray<float> MaxSpeed;
//
//};
//
//USTRUCT()
//struct FTest : public FPKMovementDataComponentStruct
//{
//	GENERATED_BODY()
//
//
//
//};