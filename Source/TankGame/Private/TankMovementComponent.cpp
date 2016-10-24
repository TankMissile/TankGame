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


//No need for override since we're replacing the entire functionality
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	auto IntendDirection = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, IntendDirection);
	
	auto RightThrow = FVector::CrossProduct(TankForward, IntendDirection).Z;

	IntendMoveForward(ForwardThrow);
	IntendTurn(RightThrow);
}