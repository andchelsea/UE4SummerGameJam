// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "sharpeningWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTVR_API UsharpeningWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float sharpeningPercentage = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor color;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float difficulty; // value from 0 to 100

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxPositionRandomizer = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float penetrationMultiplier = 1;

	UFUNCTION(BlueprintCallable)
	void Activate(float diff);

	UFUNCTION(BlueprintCallable)
	void Deactivate();

	UFUNCTION(BlueprintCallable)
	void AddPenetration(float pen);

	UFUNCTION(BlueprintCallable)
	float GetQuality();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool isActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float currPositionRandomizer = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float totalPenetration = 0.f;

private:
	FRandomStream mStream;
};
