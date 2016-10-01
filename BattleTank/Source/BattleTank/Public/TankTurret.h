// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent)) //, hidecatergories= ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//-1 is max ccw rotation and 1 is max cw rotation
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; //sensible default
};
