// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank Not Found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank : %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TODO Move towards player
		
		//Aim at Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//TODO Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	AActor* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}

