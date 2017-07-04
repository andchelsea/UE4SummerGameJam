// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "sharpeningWidget.generated.h"

/**
 * 
 */
UCLASS()
class MCOOKIECRAVERS_SHOP_API UsharpeningWidget : public UUserWidget
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
	// Get quality between 0 and 1
	float GetQuality(); 


protected:

	UPROPERTY(BlueprintReadOnly)
	bool isActive = false;	

	UPROPERTY(BlueprintReadOnly)
	float totalPenetration = 0.f;

	UPROPERTY(BlueprintReadOnly)
	float mLeftWidgetPosition = 0.f;

	UPROPERTY(BlueprintReadOnly)
	float mRightWidgetPosition = 0.f;

private:
	FRandomStream mStream;
};
