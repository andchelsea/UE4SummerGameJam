// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnvilNote.h"
#include "AnvilSongData.h"
#include "Item.h"
#include "Anvil.generated.h"

UCLASS()
class TESTVR_API AAnvil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnvil();

	UFUNCTION(BlueprintCallable)
	void StartGame(WeaponType type);

	UFUNCTION(BlueprintCallable)
	void StopGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAnvilSongData> weapons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isIngotPlaced = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isGamePlaying = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float noteSpawnHeight = 55.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float noteSpawnWidth = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float noteSpawnLength = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int gridWidth = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int gridLength = 2;


protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int selectedWeapon = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	WeaponType weaponType;

	int nextNote = 0;
	float nextNoteTime = 0.0f;
	float timePassed = 0.0f;
	float score = 0.0f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* hammerHitSound;

	class UAudioComponent* audioComponentHit;
	class UAudioComponent* audioComponentSong;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UClass* noteObj;
	TArray<AAnvilNote*> noteObjects;
	int32_t nextNoteToSpawn = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AItem* ingotOnAnvil;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool widgetsActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AItem*> ingotsInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform ingotTransform;

	TArray<int> noteGrid;
};
