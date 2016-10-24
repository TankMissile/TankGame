// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class ATank;
class UTankTread;

/**
 * Responsible for controlling the tank treads
 */
UCLASS(meta = (BlueprintSpawnableComponent), ClassGroup = (Custom))
class TANKGAME_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

	//Turns applies throttle to both treads based on throw, causing the tank to turn clockwise if positive, or counter-clockwise if negative
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurn(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Init(UTankTread* Left, UTankTread* Right);


	
private:
	UTankTread* TreadLeft;
	UTankTread* TreadRight;
};
