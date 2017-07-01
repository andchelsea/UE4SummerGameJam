// Fill out your copyright notice in the Description page of Project Settings.

#include "Hammer.h"


// Sets default values
AHammer::AHammer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHammer::BeginPlay()
{
	Super::BeginPlay();
	
	initialTransform = GetActorTransform();
}

// Called every frame
void AHammer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

//	if (isHeld)
//	{
//		timeSinceDropped = 0.0f;
//	}
//	else if (GetActorLocation() != initialTransform.TransformPosition)
//	{
//		timeSinceDropped += DeltaTime;
//
//		if (timeSinceDropped > 2.0f)
//		{
//			TeleportTo(initialTransform.GetLocation(), initialTransform.GetRotation().Rotator());
//		}
//	}
//	else // High, not held
//	{
//		timeSinceDropped = 0.0f;
//	}
}

