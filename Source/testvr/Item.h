// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"

#include "Item.generated.h"

// Example Materials
UENUM(Blueprintable)
enum class MaterialType : uint8
{
	kCopper,
	kIron,
	kSteel,
	kMax
};

// Example Weapons
UENUM(Blueprintable)
enum class WeaponType : uint8
{
	kSword,
	kAxe,
	kLance,
	kMax
};

UENUM(Blueprintable)
enum class ItemState : uint8
{
	kOre,
	kSmelting,
	kIngot,
	kForging,
	kDullWeapon,
	kSharpening,
	kSharpWeapon,
	kMax
};

UCLASS()
class TESTVR_API AItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Change Item States

	UFUNCTION(BlueprintCallable)
	bool SetIngot();
	//UFUNCTION(BlueprintCallable)
	//void SetWeapon(WeaponType type);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
	float mItemQuality;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
	ItemState mState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
	WeaponType mWeaponType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
	MaterialType mMaterialType;

};
