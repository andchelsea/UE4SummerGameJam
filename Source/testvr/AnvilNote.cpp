// Fill out your copyright notice in the Description page of Project Settings.

#include "AnvilNote.h"


// Sets default values
AAnvilNote::AAnvilNote()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAnvilNote::Activate()
{
	//PrimaryActorTick.bCanEverTick = true;
	bHidden = false;
	active = true;

	timePassed = 0.0f;
}

void AAnvilNote::Deactivate()
{
	//PrimaryActorTick.bCanEverTick = false;
	bHidden = true;
	active = false;
}

// Called when the game starts or when spawned
void AAnvilNote::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnvilNote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

