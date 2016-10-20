// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
private:
	//crosshair percentage across screen
	UPROPERTY(EditAnywhere)
	float CHPosX = 0.5;
	UPROPERTY(EditAnywhere)
	float CHPosY = 0.5;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;

	ATank* GetControlledTank() const;

	//Move towards the crosshair such that a projectile will hit whatever is being aimed at
	void AimTowardCrosshair();
	bool GetCrosshairHitLocation(FVector&) const;
	bool GetLookDirection(FVector2D, FVector&) const;
	bool GetLookVectorHitLocation(FVector&, FVector) const;

	void BeginPlay() override;
	void Tick(float DeltaTime) override;
};
