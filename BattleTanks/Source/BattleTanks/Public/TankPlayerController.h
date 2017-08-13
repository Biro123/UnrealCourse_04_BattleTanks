// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;

	// Override and extend the functionality of the BeginPlay method of AActor (A parent of PlayerController)
	virtual void BeginPlay() override;   

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Start moving the barrel to hit where the crosshair collides with the world
	void AimTowardsCrosshair();

	// Return an OUT parameter - True if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
