// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BallisticsAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

/**
 * Ballistics Aiming Component calculates the angle at which a projectile must be fired
 * in order to land at the point raytraced through the center of the screen
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UBallisticsAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBallisticsAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void AimAt(FVector, float);

	void SetBarrelReference(UTankBarrel*);
	void SetTurretReference(UTankTurret*);

private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;
	
	void MoveBarrel(FVector);
};
