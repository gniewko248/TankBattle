// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPlayerController();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingComp);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:		
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333f;

	float LineTraceRange = 1000000.0f;

	virtual void Tick(float DeltaTime) override;


	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;
	
	bool ATankPlayerController::GetLookDirection(FVector2D, FVector&) const;

	bool GetLookVectorHitLocation(FVector, FVector&) const;
	
	
};
