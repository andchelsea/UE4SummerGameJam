// Fill out your copyright notice in the Description page of Project Settings.

#include "Furnace.h"


// Sets default values
AFurnace::AFurnace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFurnace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	mCurrentHeat -= DeltaTime;

	if (mCurrentHeat <= 0.f)
	{
		mCurrentHeat = 0.f;
		return;
	}
	
	int numWeapons = mWeapons.Num();

	for (int i = 0; i < numWeapons; ++i)
	{
		//mWeapons[i].IncreaseHeatLevel(DeltaTime);
	}

}

void AFurnace::Activate()
{
	mCurrentHeat = maxHeat;
}

