// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster.h"
#include "BehaviorTree/BehaviorTree.h"
#include "time.h"

// Sets default values
AMonster::AMonster()
	:StallLocation(230.0f ,110.0f ,0.0f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bUseRVOAvoidance = true;

	srand(time(NULL));

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();

	switch (rand() % 3)//set weapon type
	{
	case 0:
		desiredWeapon = WeaponType::kSword;
		break;
	case 1:
		desiredWeapon = WeaponType::kAxe;
		break;
	case 2:
		desiredWeapon = WeaponType::kLance;
		break;
	}

	switch (rand() % 3)//set weapon material
	{
	case 0:
		desiredMaterial = MaterialType::kCopper;
		break;
	case 1:
		desiredMaterial = MaterialType::kGold;
		break;
	case 2:
		desiredMaterial = MaterialType::kIron;
		break;
	}
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

