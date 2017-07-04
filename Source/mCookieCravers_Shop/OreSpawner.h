// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"
#include "OreSpawner.generated.h"

UCLASS()
class MCOOKIECRAVERS_SHOP_API AOreSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOreSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool CheckSpace() { return mNumOres < maxOre; }

	UFUNCTION(BlueprintCallable)
	void AddOre() { mNumOres++; }

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int maxOre;

protected:
	int mNumOres = 0;
};
