#include "PKPlayerController.h"
#include <EnhancedInputSubsystems.h>
#include "Oblig2/Components/PKMovementDataComponent.h"
#include "EnhancedInputComponent.h"
#include "Oblig2/Characters/PKCharacterPlayer.h"

void APKPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Setting up the MovementDataComponent
	APawn* PlayerCharacter = GetPawn();
	if (PlayerCharacter)
	{
		MovementDataComponent = PlayerCharacter->FindComponentByClass<UPKMovementDataComponent>();
	}

	// Adding the input mapping context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerMappingContext, 0);
	}
}

void APKPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Binding the inputs to functions
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &APKPlayerController::MoveForward);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &APKPlayerController::MoveRight);
	}
}

void APKPlayerController::MoveForward(const FInputActionValue& Value)
{
	// Moving the character forward
	if (MovementDataComponent)
	{
		float ForwardValue = Value.Get<float>();
		MovementDataComponent->Acceleration.X = ForwardValue * MovementDataComponent->MaxSpeed;
	}
}

void APKPlayerController::MoveRight(const FInputActionValue& Value)
{
	// Moving the character to the right
	if (MovementDataComponent)
	{
		float RightValue = Value.Get<float>();
		MovementDataComponent->Acceleration.Y = RightValue * MovementDataComponent->MaxSpeed;
	}
}