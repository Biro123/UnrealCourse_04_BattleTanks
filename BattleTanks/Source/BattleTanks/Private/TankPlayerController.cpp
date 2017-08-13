// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();   // Ensures that BeginPlay on AActor is being called
	
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController NOT Controlling Tank: %s"), *GetOwner()->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Controlling Tank: %s"), *ControlledTank->GetName())
	}

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

