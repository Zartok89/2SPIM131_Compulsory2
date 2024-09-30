// Fill out your copyright notice in the Description page of Project Settings.


#include "PKMovementDataComponent.h"

// Sets default values for this component's properties
UPKMovementDataComponent::UPKMovementDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

    // Initialize default values 
    Velocity = FVector::ZeroVector;  
    Acceleration = FVector::ZeroVector;  
    MaxSpeed = 600.0f;

}