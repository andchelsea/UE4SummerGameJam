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

	audioComponentHit = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component Hit"));
	audioComponentHit->bAutoActivate = false;
	audioComponentHit->SetupAttachment(RootComponent);
	audioComponentHit->SetRelativeLocation(FVector(0.0f, 0.0f, 55.0f));

	if (hammerHitSound->IsValidLowLevelFast())
	{
		audioComponentHit->SetSound(hammerHitSound);
	}

	audioComponentSong = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component Song"));
	audioComponentSong->bAutoActivate = false;
	audioComponentSong->SetupAttachment(RootComponent);
	audioComponentSong->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
}

// Called when the game starts or when spawned
void AAnvil::BeginPlay()
{
	Super::BeginPlay();

	// Initialize note pool to 10 items
	for (int i = 0; i < 10; ++i)
	{
		FVector spawnLocation(0.0f, 0.0f, 0.0f);
		FRotator spawnRotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters spawnInfo;
		spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AAnvilNote* note = GetWorld()->SpawnActor<AAnvilNote>(noteObj, spawnLocation, spawnRotation, spawnInfo);
		note->Deactivate();
		noteObjects.Add(note);
	}

	//StartGame();
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
			// Check for next note spawn
			if (timePassed > (weapons[selectedWeapon].notes[nextNote] - 1.5f))
			{
				// Spawn a note
				float x = (2.0f * noteSpawnLength * rand() / (float)RAND_MAX) - noteSpawnLength;
				float y = (2.0f * noteSpawnWidth * rand() / (float)RAND_MAX) - noteSpawnWidth;
				float z = noteSpawnHeight;
				noteObjects[nextNoteToSpawn]->TeleportTo(GetActorLocation() + FVector(x, y, z), FRotator());

				noteObjects[nextNoteToSpawn]->Activate();

				nextNoteToSpawn = (nextNoteToSpawn + 1) % 10;
				++nextNote;

				// Make sure we dont go over the max number of notes
				if (nextNote < weapons[selectedWeapon].notes.Num())
				{
					//nextNoteTime = weapons[selectedWeapon].startTime + weapons[selectedWeapon].notes[nextNote] * weapons[selectedWeapon].secondsPerBeat - 0.0f;// noteObjects[nextNoteToSpawn]->hitTime;
				}
			}
		}

		// Check if any notes have been hit or have expired.
		for (int32_t i = 0; i < noteObjects.Num(); ++i)
		{
			if (!noteObjects[i]->active) continue;

			// Check if it was hit
			if (noteObjects[i]->hit)
			{
				float timeDifference = fabs(noteObjects[i]->timePassed - noteObjects[i]->hitTime);

				// Calculate score based on time accuracy
				float noteScore = fmaxf(1.0f - timeDifference, 0.0f);
				score += noteScore;
				
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
	score = 0.0f;

	weaponType = type;
	ingotOnAnvil->SetWeaponType(weaponType);
	ingotOnAnvil->SetGrabbable(false);

	selectedWeapon = static_cast<int>(type);

	//nextNoteTime = nextNoteTime = weapons[selectedWeapon].startTime + weapons[selectedWeapon].notes[0] * weapons[selectedWeapon].secondsPerBeat - 0.0f;// noteObjects[0]->hitTime;

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

	for (int32_t i = 0; i < 10; ++i)
	{
		if (noteObjects[i]->active)
		{
			noteObjects[i]->Deactivate();
		}
	}

	ingotOnAnvil->SetToWeapon(score);
	ingotOnAnvil->SetGrabbable(true);
	ingotOnAnvil = nullptr;
}
