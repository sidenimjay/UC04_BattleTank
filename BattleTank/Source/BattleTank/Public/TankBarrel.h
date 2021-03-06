// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//-1 is max downward and 1 is max upward movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category= Setup)
	float MaxDegreesPerSecond = 10; //sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;

};
