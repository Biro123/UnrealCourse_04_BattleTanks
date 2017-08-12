// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();   // Ensures that BeginPlay on AActor is being called
	
	ControlledTank = GetcontrolledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("ControlledTank not found for %s"), *GetOwner()->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found Controlled Tank: %s"), *ControlledTank->GetName())
	}

}


ATank* ATankPlayerController::GetcontrolledTank() const
{
	return Cast<ATank>(GetPawn());
}

