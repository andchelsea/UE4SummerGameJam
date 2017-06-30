// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mState = ItemState::kOre;
	mMaterialType = (Material)FMath::RandRange(0, (int)Material::kMax);

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

void AItem::Grab(USceneComponent* controller)
{
	mMesh->SetSimulatePhysics(false);
	AttachRootComponentTo(controller);
}

void AItem::Release()
{
	DetachFromActor(FDetachmentTransformRules(EDetachmentRule::KeepWorld, false));
	mMesh->SetSimulatePhysics(true);
}

void AItem::SetIngot(USkeletalMeshComponent* mesh, UMaterialInstanceDynamic* material)
{
	mState = ItemState::kIngot;
	mMesh = mesh;
	mMaterial = material;
}

void AItem::SetWeapon(WeaponType type)
{
}

