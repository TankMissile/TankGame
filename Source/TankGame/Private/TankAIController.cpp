// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PTank) {
		//Move Towards Player
		MoveToActor(PTank, TargetDistance);

		//Aim at player
		ControlledTank->AimAt(PTank->GetActorLocation());

		//Fire if ready
		ControlledTank->Fire();
	}
}