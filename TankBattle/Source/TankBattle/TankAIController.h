// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	virtual	void BeginPlay() override; //public if you want to inherit from this class

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;


	
	
	
};
