// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

private:
	//How close the AI will get to the player
	UPROPERTY(EditDefaultsOnly, Category = Pathfinding)
	float TargetDistance = 3000.0f;
};
