// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrindStone.generated.h"

UCLASS()
class TESTVR_API AGrindStone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrindStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grind)
	float grindSpeed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grind)
	float lastIncrease = 0.0f;
};
