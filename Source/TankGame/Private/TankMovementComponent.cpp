// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankMovementComponent.h"
#include "TankTread.h"

//Sets the references to both treads
void UTankMovementComponent::Init(UTankTread* Left, UTankTread* Right) {

	TreadLeft = Left;
	TreadRight = Right;
}


void UTankMovementComponent::IntendMoveForward(float Throw) {
	if (TreadLeft) {
		TreadLeft->SetThrottle(Throw);
	}
	if (TreadRight) {
		TreadRight->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendTurn(float Throw) {
	if (TreadLeft) {
		TreadLeft->SetThrottle(Throw);
	}
	if (TreadRight) {
		TreadRight->SetThrottle(-Throw);
	}
}