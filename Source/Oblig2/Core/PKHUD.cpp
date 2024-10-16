// Fill out your copyright notice in the Description page of Project Settings.

#include "PKHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Oblig2/Characters/PKCharacterPlayer.h"
#include "Oblig2/Components/PKAttributeDataComponent.h"
#include "Oblig2/UI/PKUserWidget.h"

APKHUD::APKHUD()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APKHUD::BeginPlay()
{
	Super::BeginPlay();

	// Create and add the User widget to the viewport
	if (UserWidgetClass)
	{
		UserWidget = CreateWidget<UPKUserWidget>(GetWorld(), UserWidgetClass);
		if (UserWidget)
		{
			UserWidget->AddToViewport();
		}
	}

	// Get the player character
	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(this, 0);
	if (PlayerCharacter)
	{
		// Get the attribute component
		UPKAttributeDataComponent* AttributeDataComponent = PlayerCharacter->FindComponentByClass<UPKAttributeDataComponent>();
		if (AttributeDataComponent)
		{
			// Bind the LevelUp handler to the event
			AttributeDataComponent->OnLevelUp.AddDynamic(this, &APKHUD::OnLevelUpHandler);

			// Initialize the level display
			if (UserWidget)
			{
				UserWidget->UpdateLevelDisplay(AttributeDataComponent->GetLevel());
			}
		}
	}
}

void APKHUD::OnLevelUpHandler(int32 NewLevel)
{
	if (UserWidget)
	{
		UserWidget->UpdateLevelDisplay(NewLevel);
	}
}