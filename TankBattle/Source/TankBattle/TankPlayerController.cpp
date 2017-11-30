// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


// Sets default values
ATankPlayerController::ATankPlayerController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent)) {
		FoundAimingComponent(AimingComponent);
	}
	//GetControlledTank();
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } //if not possessing
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FVector OutHitLocation; //OUT parameter
	if (GetSightRayHitLocation(OutHitLocation)) {
		AimingComponent->AimAt(OutHitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation =FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	FVector LookDirection;
	if (ensure(GetLookDirection(ScreenLocation, LookDirection))) {
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
	FVector CameraWorldLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FCollisionQueryParams params = FCollisionQueryParams();//
	params.AddIgnoredActor(GetPawn());//added to ignore players tank

	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (ensure(GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, params))) {
		OutHitLocation = HitResult.Location;
		return true;
	}
	return false;
}




