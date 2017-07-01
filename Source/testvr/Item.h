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
	kGold,
	kMax
};

// Example Weapons
UENUM(Blueprintable)
enum class WeaponType : uint8
{
	kSword,
	kLance,
	kAxe,
	kNone,
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

	//UFUNCTION(BlueprintCallable)
	//void SetWeapon(WeaponType type);


// Ore State
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float maxHeatRequired= 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float qualityDecreaseRate = 1.f; // Per 1.f extra heat.

	UFUNCTION(BlueprintCallable)
	float GetCurrentHeatPercentage() { return mCurrentHeat / maxHeatRequired; }

	UFUNCTION(BlueprintCallable)
	bool IsInFurnace() { return furnaceId > -1; }

	int furnaceId = -1;

	// increases heat and returns if can change to ingot.
	bool IncreaseHeat(float heat);
	void CalculateIngotQuality();

	// Grind State
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GrindState)
	float grindAmount = 0.0f;

private:	
	float mCurrentHeat = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


// Global State
public: 
	
	// Setters
	UFUNCTION(BlueprintCallable)
	void SetQuality(float quality) { mItemQuality = quality; }
	UFUNCTION(BlueprintCallable)
	void SetState(ItemState state) { mState = state; }
	UFUNCTION(BlueprintCallable)
	void SetWeaponType(WeaponType type) { mWeaponType = type; }
	UFUNCTION(BlueprintCallable)
	void SetMaterialType(MaterialType type) { mMaterialType = type; }
	UFUNCTION(BlueprintCallable)
	void SetGrab(bool grab) { mIsGrabbed = grab; }

	// Getters
	UFUNCTION(BlueprintCallable)
	float GetQuality() { return mItemQuality; }
	UFUNCTION(BlueprintCallable)
	ItemState GetState() { return mState; }
	UFUNCTION(BlueprintCallable)
	WeaponType GetWeaponType() { return mWeaponType; }
	UFUNCTION(BlueprintCallable)
	MaterialType GetMaterialType() { return mMaterialType; }
	UFUNCTION(BlueprintCallable)
	bool GetGrab() { return mIsGrabbed; }


protected:

	float mItemQuality = 1.f;
	ItemState mState;
	WeaponType mWeaponType;
	MaterialType mMaterialType;
	bool mIsGrabbed = false;

};
