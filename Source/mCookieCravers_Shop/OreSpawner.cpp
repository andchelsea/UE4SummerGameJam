// Fill out your copyright notice in the Description page of Project Settings.

#include "OreSpawner.h"


// Sets default values
AOreSpawner::AOreSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOreSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOreSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
