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
	mOre.Reserve(maxOre);
}

// Called every frame
void AFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	mCurrentHeat -= DeltaTime * heatDecreaseMultiplier;

	if (mCurrentHeat <= 0.f)
	{
		mCurrentHeat = 0.f;
		return;
	}
	
	for (auto ore : mOre)
	{
		if (ore->IncreaseHeat(DeltaTime * heatDecreaseMultiplier))
		{
			ore->SetState(ItemState::kIngot);
			ore->SetToIngot();
		}
		
	}

}

void AFurnace::Activate()
{
	mCurrentHeat = maxHeat;
}

void AFurnace::AddOre(AItem* item)
{
	if (item->GetState() != ItemState::kOre  || mOre.Num() >= maxOre)
	{
		// TODO: return item back to starting point?
		return;
	}

	mOre.Add(item);
	item->furnaceId = mOre.Num() - 1;
}

void AFurnace::RemoveItem(AItem* item)
{
	if (item->furnaceId != -1)
	{
		mOre.RemoveAt(item->furnaceId);
		item->furnaceId = -1;
		if (item->GetState() == ItemState::kIngot)
		{
			item->CalculateIngotQuality();
		}
	}
}
