// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Engine.h"

// Sets default values
AItem::AItem()
	: mState(ItemState::Ore)
	, mWeaponType(WeaponType::None)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AItem::Grab(USceneComponent* controller)
//{
//	mMesh->SetSimulatePhysics(false);
//	AttachRootComponentTo(controller);
//}
//
//void AItem::Release()
//{
//	DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, false));
//	mMesh->SetSimulatePhysics(true);
//}

bool AItem::IncreaseHeat(float heat)
{
	mCurrentHeat += heat;
	return mCurrentHeat >= maxHeatRequired && mState == ItemState::Ore;
}

void AItem::CalculateIngotQuality()
{
	ingotQuality -= ((mCurrentHeat - maxHeatRequired)*qualityDecreaseRate) * 0.01f;
}

void AItem::SetToIngot_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "item c++ called");
}

void AItem::SetToWeapon_Implementation(float quality)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, "item c++ called");
}



//void AItem::SetWeapon(WeaponType type)
//{
//}

