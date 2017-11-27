// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


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
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerControlled not possesing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerControler possesing: %s"), *(ControlledTank->GetName()))
	}
	GetControlledTank();
	
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());	
}



