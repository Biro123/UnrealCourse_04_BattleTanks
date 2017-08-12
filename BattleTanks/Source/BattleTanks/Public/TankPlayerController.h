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
	
public:
	ATank* GetcontrolledTank() const;

	// Override and extent the functinoality of the BeginPlay method of AActor (A parent of PlayerController)
	virtual void BeginPlay() override;   
	
private:
	ATank* ControlledTank = nullptr;
	
};
