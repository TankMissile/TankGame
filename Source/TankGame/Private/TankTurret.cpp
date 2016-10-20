// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankTurret.h"



void UTankTurret::RotateAzimuth(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewAzimuth = RelativeRotation.Yaw + AzimuthChange;

	SetRelativeRotation(FRotator(0, NewAzimuth, 0));
}
