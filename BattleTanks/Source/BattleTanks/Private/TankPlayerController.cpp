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

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}
	

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OutParameter
	
	if (GetSightRayHitLocation(HitLocation)) // has a side-effect, is going to line-trace
	{
		// TODO Tell controlled tank to aim at this point

		UE_LOG(LogTemp, Warning, TEXT("HitLocation = %s"), *HitLocation.ToString());
	}

}

// Get world location when linetraced through crosshair, returns true if landscape hit
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);

	// Find the Crosshair Position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	// 'De-Project' the screen position of the crosshair to a world location
	FVector LookDirection;
	if ( GetLookDirection(ScreenLocation, LookDirection) )
	{
		// Line-trace along that LookDirection and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	// TODO Should not simply return true
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // To Discard
	
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	
	/// Setup Query Parameters
	FCollisionQueryParams TraceQueryParameters(FName(TEXT("")), false, GetOwner());
	FCollisionResponseParams TraceResponseParameters(ECollisionResponse::ECR_Block);

	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility,
			TraceQueryParameters,
			TraceResponseParameters
			)
		)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}

	// Hit not found
	OutHitLocation = FVector(0);
	return false;
}
