// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;  

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }  
	if (!Turret) { return; }
		
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the Out Launch Velocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
		{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); // Convert full vector to unit vector 
		MoveBarrelTowards(AimDirection);
		}

	/// if no solution found - do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	/// Find current elevation
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();

	/// convert AimDirection to horizontal and vertical rotators
	auto AimAsRotator = AimDirection.Rotation();

	/// apply the difference
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	/// elevate the barrel and rotate the Turret
	Barrel->Elevate(DeltaRotator.Pitch);  
	Turret->Rotate(DeltaRotator.Yaw);
}

