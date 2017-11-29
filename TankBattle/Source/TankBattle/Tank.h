// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable)
		void Fire();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000.0f; //TODO find reasonable value

	virtual void BeginPlay() override;

protected:


	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	

public:	

	void AimAt(FVector);

private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	UClass* ProjectileBlueprint; 

	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	double ReloadTimeInSeconds = 3.0f;

	double LastFireTime = 0.0;
	
	
};
