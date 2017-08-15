// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

// Forward Declaration
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Override and extend the functionality of the BeginPlay method of AActor (A parent of PlayerController)
	virtual void BeginPlay() override;   

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	ATank* GetControlledTank() const;

	// Start moving the barrel to hit where the crosshair collides with the world
	void AimTowardsCrosshair();

	// Return an OUT parameter - True if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// Returns LookDirection as a Vector
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// Returns location in the world hit by the ray-trace as a Vector
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
