#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <EnhancedInputLibrary.h>
#include "PKPlayerController.generated.h"

class UPKMovementDataComponent;

/**
 *
 */
UCLASS()
class OBLIG2_API APKPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void MoveForward(const FInputActionValue& Value);
	void MoveRight(const FInputActionValue& Value);
	void StopMoveForward();
	void StopMoveRight();

	/*
	 * IMC and Actions
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveForwardAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveRightAction;

	/*
	* Variables
	*/
	UPKMovementDataComponent* MovementDataComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float MovementSpeed{ 5.f };

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
