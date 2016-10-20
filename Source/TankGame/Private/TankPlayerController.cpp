// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair() {
	if (!GetControlledTank()) return;

	FVector HitLocation;

	//Get World Position through linetrace of crosshair
	if (GetCrosshairHitLocation(HitLocation)) {
		//Aim towards that position
		GetControlledTank()->AimAt(HitLocation);
	}
}

//Raytraces through the crosshair, returns true if hit something
bool ATankPlayerController::GetCrosshairHitLocation(FVector& HitLocation) const {
	//Find crosshair position
	int32 VPSizeX, VPSizeY;
	GetViewportSize(VPSizeX, VPSizeY);
	auto ScreenLocation = FVector2D(VPSizeX * CHPosX, VPSizeY * CHPosY);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// Raytrace along that direction
		GetLookVectorHitLocation(HitLocation, LookDirection);
		return true;
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	//De-project screen position of crosshair to world direction
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

//Perform line trace and update HitLocation
bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)){
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0.0);
	return false;
}