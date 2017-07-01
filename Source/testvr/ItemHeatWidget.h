// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemHeatWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTVR_API UItemHeatWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float heatPercentage = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isActive;
};
