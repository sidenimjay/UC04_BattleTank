// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ctank = GetControlledTank();

	UE_LOG(LogTemp, Warning, TEXT("PC BeginPlay %s"), *ctank->GetName() )
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>( GetPawn());
}
