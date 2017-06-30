// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnvilNote.generated.h"

UCLASS()
class TESTVR_API AAnvilNote : public AActor
{
	GENERATED_BODY()
public:	
	
	// Sets default values for this actor's properties
	AAnvilNote();

	void Activate();
	void Deactivate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float timePassed = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float hitTime = 1.5f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float totalTime = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool active = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool hit = false;
	
};
