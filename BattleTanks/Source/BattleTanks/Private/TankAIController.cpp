// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();   // Ensures that BeginPlay on AActor is being called

	ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController NOT controlling Tank: %s"), *GetOwner()->GetName())
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController Controlling Tank: %s"), *ControlledTank->GetName())
	}


	PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController can't find PlayerTank") )
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player Tank %s"),	*PlayerTank->GetName())
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerTank) { return; }
	if (!ControlledTank) { return; }

	// TODO Move towards Player

	// Aim at the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// TODO Fire when ready
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

