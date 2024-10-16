#include "PKPlayerController.h"
#include <EnhancedInputSubsystems.h>
#include "Oblig2/Components/PKMovementDataComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Oblig2/Characters/PKCharacterPlayer.h"

void APKPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Setting up the MovementDataComponent
	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(this, 0);
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
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Completed, this, &APKPlayerController::StopMoveForward);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &APKPlayerController::MoveRight);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Completed, this, &APKPlayerController::StopMoveRight);
	}
}

void APKPlayerController::MoveForward(const FInputActionValue& Value)
{
	// Moving the character forward
	if (MovementDataComponent)
	{
		float ForwardValue = Value.Get<float>();

		MovementDataComponent->Acceleration.X = ForwardValue * MovementSpeed;

		UE_LOG(LogTemp, Warning, TEXT("Acceleration: %s"), *MovementDataComponent->Acceleration.ToString());
	}
}

void APKPlayerController::MoveRight(const FInputActionValue& Value)
{
	// Moving the character to the right
	if (MovementDataComponent)
	{
		float RightValue = Value.Get<float>();

		// Update acceleration based on input
		MovementDataComponent->Acceleration.Y = RightValue * MovementSpeed;

		UE_LOG(LogTemp, Warning, TEXT("Acceleration: %s"), *MovementDataComponent->Acceleration.ToString());
	}
}

void APKPlayerController::StopMoveForward()
{
	MovementDataComponent->Acceleration.X = 0.f;
	MovementDataComponent->Velocity.X = 0.f;
}

void APKPlayerController::StopMoveRight()
{
	MovementDataComponent->Acceleration.Y = 0.f;
	MovementDataComponent->Velocity.Y = 0.f;
}