// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTread.generated.h"

/**
 * TankTread is used to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankTread : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throt);

	UPROPERTY(EditDefaultsOnly, Category = Input)
	float MaxThrottle = 20.0f;
	UPROPERTY(EditDefaultsOnly, Category = Input)
	float MaxReverse = -10.0f;

	//Per track, in newtons
	UPROPERTY(EditDefaultsOnly, Category = Input)
	float MaxDrivingForce = 400000.0f; //Assume 40 ton tank and 1g of acceleration
};
