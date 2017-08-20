// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force - and to apply force to tank
 */
UCLASS(meta = (BlueprintSpawnableComponent)) 
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets a throttle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max force per track, in Newtons
	UPROPERTY(EditAnywhere)
	float TrackMaxDrivingForce = 400000.f; // Assume 40ton tank at 10m/s/s accel
		
};
