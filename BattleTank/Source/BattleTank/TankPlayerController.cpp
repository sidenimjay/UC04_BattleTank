// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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
	//AimAtCursor
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	//Get world location through linetrace of crosshair
	//if hits landscape
		//tell controlled tank to aim at this point

}