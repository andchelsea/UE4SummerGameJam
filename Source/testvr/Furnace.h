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
	void AddOre(AItem* item);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(AItem* item);

	UFUNCTION(BlueprintCallable)
		float GetCurrentHeatPercentage();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Furnace)
	int maxOre;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Furnace)
	float maxHeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Furnace)
	float heatDecreaseMultiplier = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade)
	int cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade)
	int maxOreIncrease;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade)
	float maxHeatIncrease;

private:
	float mCurrentHeat = 0;
	TArray<AItem*> mOre;
	
};
