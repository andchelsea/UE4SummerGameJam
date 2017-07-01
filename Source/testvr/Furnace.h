// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Item.h"
#include "Furnace.generated.h"

UCLASS()
class TESTVR_API AFurnace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFurnace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)		
	void Activate();

	UFUNCTION(BlueprintCallable)
	bool AddOre(AItem* item);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(AItem* item);

	UFUNCTION(BlueprintCallable)
	float GetCurrentHeatPercentage();

	UFUNCTION(BlueprintCallable)
	int GetNumItems() {	return mOre.Num(); }

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Furnace)
	int maxOre = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Furnace)
	float maxHeat = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Furnace)
	float heatDecreaseMultiplier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade)
	int cost = 40;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade)
	int maxOreIncrease = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade)
	float maxHeatIncrease = 20.f;

private:
	float mCurrentHeat = 0;
	TArray<AItem*> mOre;

	float mNumOres;
	
};
