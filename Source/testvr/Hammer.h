// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hammer.generated.h"

UCLASS()
class TESTVR_API AHammer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHammer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float timeSinceDropped = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isHeld = false;

	FTransform initialTransform;
};
