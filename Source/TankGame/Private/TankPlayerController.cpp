// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	if (!GetControlledTank()) {
		UE_LOG(LogTemp, Error, TEXT("Player Controller: Tank not possessed!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play! Pawn is: %s"), *GetControlledTank()->GetName())
	}
}


