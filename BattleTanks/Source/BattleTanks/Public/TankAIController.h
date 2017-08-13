// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Override and extend the functionality of the BeginPlay method of AActor (A parent of PlayerController)
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank* PlayerTank = nullptr;

	ATank* ControlledTank = nullptr;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;

		
};
