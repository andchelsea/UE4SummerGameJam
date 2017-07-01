// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTVR_API IItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Ore State")
		void SetToIngot();
};

