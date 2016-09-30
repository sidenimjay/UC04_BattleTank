// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = GetControlledTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No Player Controller Found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PC BeginPlay %s"), *PlayerTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation;
	
	//Get world location through linetrace of crosshair
	bool result = bGetSightRayHitLocation(HitLocation);
	//if hits landscape
	if (bGetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);

	}
}

bool ATankPlayerController::bGetSightRayHitLocation(FVector &HitLocation) const
{
	bool result = false;
	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector LookDirection;
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	if( bGetLookDirection(ScreenLocation, LookDirection))
	{
		result = bGetLookVectorLocation(LookDirection, HitLocation);
	}

	return result;
}

bool ATankPlayerController::bGetLookVectorLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	FVector CameraPosition = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = CameraPosition + LookDirection*LineTraceRange;
	bool result = false;
	result = GetWorld()->LineTraceSingleByChannel(HitResult, CameraPosition, EndLocation, ECollisionChannel::ECC_Visibility);

	if (result)
	{
		HitLocation = HitResult.Location;
		//UE_LOG(LogTemp, Warning, TEXT("Actor Hit is : %s"), *HitResult.GetActor()->GetClass()->GetName())
	}
	return result;
}

bool ATankPlayerController::bGetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation;

	//De-project screen position of the crosshair to world direction
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}
