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
	// TODO - limit
	mOre.AddDefaulted(10);
	for (auto ore : mOre)
	{
		ore = nullptr;
	}
}

// Called every frame
void AFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	mCurrentHeat -= DeltaTime * heatDecreaseMultiplier;
	
	for (int i = 0; i < maxOre; ++i)
	{
		if (mOre[i] == nullptr)
			continue;

		AItem& ore = *mOre[i];

		if (ore.GetGrab())
		{
			potentialOres.Push(&ore);
			RemoveItem(&ore);
			continue;
		}

		if (mCurrentHeat <= 0.f)
		{
			continue;
		}

		if (ore.IncreaseHeat(DeltaTime * heatDecreaseMultiplier))
		{
			ore.SetState(ItemState::Ingot);
			ore.SetToIngot();
		}
		
	}

}

void AFurnace::Activate()
{
	mCurrentHeat = maxHeat;
}

bool AFurnace::AddOre(AItem* item)
{
	if (item->GetState() != ItemState::Ore  || mNumOres >= maxOre)
	{
		return false;
	}

	mNumOres++;

	for (int i = 0; i < maxOre; ++i)
	{
		if (mOre[i] == nullptr)
		{
			mOre[i] = item;
			item->furnaceId = i;
			return true;
		}
	}
	return false;
}

void AFurnace::RemoveItem(AItem* item)
{
	if (item->furnaceId != -1)
	{
		mOre[item->furnaceId] = nullptr;
		item->furnaceId = -1;
		mNumOres--;
		if (item->GetState() == ItemState::Ingot)
		{
			item->CalculateIngotQuality();
		}
	}
}

float AFurnace::GetCurrentHeatPercentage()
{
	return mCurrentHeat / maxHeat;
}

void AFurnace::RemovePotentialOre(int index)
{
	potentialOres.RemoveAt(index);
}