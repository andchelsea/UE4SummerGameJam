// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeatWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTVR_API UHeatWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float heatPercentage = 0;
};
