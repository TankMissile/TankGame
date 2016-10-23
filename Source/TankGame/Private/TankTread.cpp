// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankTread.h"



void UTankTread::SetThrottle(float throt) {
	throt = throt * MaxThrottle;
	//throt = FMath::Clamp<float>(throt, MaxReverse, MaxThrottle);

	UE_LOG(LogTemp, Warning, TEXT("%s: Throttle at %f"), *GetName(), throt);

	auto ForceApplied = GetForwardVector() * throt * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
