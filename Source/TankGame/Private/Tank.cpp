// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "BallisticsAimingComponent.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AimingComponent = CreateDefaultSubobject<UBallisticsAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComp)
{
	Super::SetupPlayerInputComponent(InputComp);

}

void ATank::AimAt(FVector TargetLocation) {
	AimingComponent->AimAt(TargetLocation, ProjectileSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	AimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {
	AimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel) { return; }

	bool isLoaded = GetWorld()->TimeSeconds > TimeLastFired + ReloadTime;
	if (isLoaded) {

		//Spawn Projectile at barrel's socket
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));

		//Launch the projectile
		Projectile->Launch(ProjectileSpeed);

		TimeLastFired = GetWorld()->TimeSeconds;
	}
}
