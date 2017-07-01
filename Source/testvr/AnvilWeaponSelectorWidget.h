// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AnvilWeaponSelectorWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTVR_API UAnvilWeaponSelectorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isActive = false;
};
