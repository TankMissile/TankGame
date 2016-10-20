// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "BallisticsAimingComponent.h"


// Sets default values for this component's properties
UBallisticsAimingComponent::UBallisticsAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBallisticsAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UBallisticsAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UBallisticsAimingComponent::SetBarrelReference(UStaticMeshComponent* b) {
	Barrel = b;
}

void UBallisticsAimingComponent::AimAt(FVector TargetLocation, float ProjectileSpeed) {
	if (!Barrel) return;

	FVector LaunchVelocity;
	FVector BarrelLocation = Barrel->GetSocketLocation(FName("Tip"));

	UE_LOG(LogTemp, Warning, TEXT("%s :"), *GetOwner()->GetName())
	
	//Calculate LaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, BarrelLocation, TargetLocation, ProjectileSpeed, ESuggestProjVelocityTraceOption::TraceFullPath, true)) {
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}


}

void UBallisticsAimingComponent::MoveBarrel(FVector AimDirection) {
	// convert aimdirection to relative vector
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("Barrel aim: %s "), *AimAsRotator.ToString());

	// start moving toward it
}