// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AnvilSongData.generated.h"

/**
 * jhbwefuhbweafiouvewaf
 */
USTRUCT(BlueprintType)
struct FAnvilSongData
{
	GENERATED_BODY()

public:

	FAnvilSongData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float beatsPerMinute = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float secondsPerBeat = 0.4285714286f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float startTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float duration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* song;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> notes;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TArray<class UMeshComponent*> meshes;
};
