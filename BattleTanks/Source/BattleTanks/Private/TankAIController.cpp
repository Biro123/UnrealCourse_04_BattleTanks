// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();   // Ensures that BeginPlay on AActor is being called

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank) { return; }
	if (!ControlledTank) { return; }

	// TODO Move towards Player

	// Aim at the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire when ready
	ControlledTank->Fire();  // TODO - don't fire every frame
	
}

