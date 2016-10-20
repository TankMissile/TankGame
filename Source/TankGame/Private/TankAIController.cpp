// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankAIController.h"


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		//Move Towards Player

		//Aim at player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PTank) {
		return nullptr;
	}
	else {
		return Cast<ATank>(PTank);
	}
}