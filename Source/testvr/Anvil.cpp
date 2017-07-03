// Fill out your copyright notice in the Description page of Project Settings.

#include "Anvil.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"

// Sets default values
AAnvil::AAnvil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	// Set up audio components
	audioComponentHit = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component Hit"));
	audioComponentHit->bAutoActivate = false;
	audioComponentHit->SetupAttachment(RootComponent);
	audioComponentHit->SetRelativeLocation(FVector(0.0f, 0.0f, 55.0f));

	audioComponentSong = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component Song"));
	audioComponentSong->bAutoActivate = false;
	audioComponentSong->SetupAttachment(RootComponent);
	audioComponentSong->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
}


// Called when the game starts or when spawned
void AAnvil::BeginPlay()
{
	Super::BeginPlay();

	// Initialize note pool to fit grid
	const int gridSize = gridWidth * gridLength;
	for (int i = 0; i < gridSize; ++i)
	{
		// Between 0 and 1
		float widthPos = (i % gridWidth) / (float)(gridWidth - 1);
		float lengthPos = floorf(i / gridWidth) / (float)(gridLength - 1);

		float x = noteSpawnWidth  * 2.0f * (widthPos  - 0.5f);
		float y = noteSpawnLength * 2.0f * (lengthPos - 0.5f);
		float z = noteSpawnHeight;

		FVector location = ingotTransform.GetLocation() + FVector(x, y, z);
		FRotator rotation = ingotTransform.Rotator();
		FActorSpawnParameters spawnInfo;
		spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AAnvilNote* note = GetWorld()->SpawnActor<AAnvilNote>(noteObj, location, rotation, spawnInfo);
		note->Deactivate();
		noteObjects.Add(note);
	}

	// Assign audio component hit sound
	if (hammerHitSound->IsValidLowLevelFast())
	{
		audioComponentHit->SetSound(hammerHitSound);
	}

	//StartGame(WeaponType::kSword);
}

// Called every frame
void AAnvil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isGamePlaying)
	{
		timePassed += DeltaTime;

		// Make sure we dont go over the max number of notes
		if (nextNote < weapons[selectedWeapon].notes.Num())
		{
			// Check if the next note is ready to be spawned
			if (timePassed > (weapons[selectedWeapon].notes[nextNote] - 1.0f))
			{
				// Find a random note that is not active
				int selectedGridSpot = 0;
				do
				{
					selectedGridSpot = rand() % noteObjects.Num();
				} while (noteObjects[selectedGridSpot]->active);

				noteObjects[selectedGridSpot]->Activate();

				++nextNote;
			}
		}

		// Check if any notes have been hit or have expired
		for (int32_t i = 0; i < noteObjects.Num(); ++i)
		{
			if (!noteObjects[i]->active) continue;

			// Check if it was hit
			if (noteObjects[i]->hit)
			{
				float timeDifference = fabs(noteObjects[i]->timePassed - noteObjects[i]->hitTime);

				// Calculate score based on time accuracy
				float noteScore = fmaxf(1.0f - timeDifference, 0.0f);
				accuracy += noteScore / weapons[selectedWeapon].notes.Num();
				
				noteObjects[i]->Deactivate();

				audioComponentHit->Play();
			}

			// Check if it has expired
			if (noteObjects[i]->timePassed > noteObjects[i]->totalTime)
			{
				noteObjects[i]->Deactivate();
			}
		}

		// Stop the game
		if (timePassed > weapons[selectedWeapon].duration)
		{
			StopGame();
		}
	}
}

void AAnvil::StartGame(WeaponType type)
{
	// Set variables
	isGamePlaying = true;
	widgetsActive = false;
	timePassed = 0.0f;
	nextNote = 0;
	accuracy = 0.0f;

	weaponType = type;
	ingotOnAnvil->SetWeaponType(weaponType);
	ingotOnAnvil->SetGrabbable(false);

	selectedWeapon = static_cast<int>(type);

	// Start song
	if (weapons[selectedWeapon].song->IsValidLowLevelFast())
	{
		audioComponentSong->SetSound(weapons[selectedWeapon].song);
		audioComponentSong->Play();
	}
}

void AAnvil::StopGame()
{
	isGamePlaying = false;

	audioComponentSong->Stop();

	for (int32_t i = 0; i < noteObjects.Num(); ++i)
	{
		if (noteObjects[i]->active)
		{
			noteObjects[i]->Deactivate();
		}
	}

	ingotOnAnvil->SetState(ItemState::DullWeapon);
	ingotsInRange.Remove(ingotOnAnvil);
	ingotOnAnvil->SetToWeapon(accuracy);
	ingotOnAnvil->SetGrabbable(true);
	//isIngotPlaced = false;
	//ingotOnAnvil = nullptr;
}
