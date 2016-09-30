// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  //must be last include!!

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	ATank* GetControlledTank() const;

	//Aim tank barrel at crosshair
	void AimAtCrosshair();


	bool bGetSightRayHitLocation(FVector &HitLocation) const;
	bool bGetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool bGetLookVectorLocation(FVector LookDirection, FVector & HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

};


