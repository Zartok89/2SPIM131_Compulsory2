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

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;  
};
