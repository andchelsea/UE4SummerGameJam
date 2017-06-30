// Fill out your copyright notice in the Description page of Project Settings.

#include "Anvil.h"
#include "Components/BoxComponent.h"

// Sets default values
AAnvil::AAnvil()
	//: noteSpawnArea(CreateDefaultSubobject<UBoxComponent>(TEXT("Note Spawn Area")))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//noteSpawnArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAnvil::BeginPlay()
{
	Super::BeginPlay();

	// Initialize note pool to 10 items
	//noteObjects.AddDefaulted(10);
	for (int i = 0; i < 10; ++i)
	{
		noteObjects.Add(NewObject<AAnvilNote>());
	}
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
			if (timePassed > weapons[selectedWeapon].notes[nextNote])
			{
				// Spawn a note
				float x = (2.0f * noteSpawnLength * rand() / (float)RAND_MAX);
				float y = (2.0f * noteSpawnWidth * rand() / (float)RAND_MAX);
				float z = noteSpawnHeight;
				noteObjects[nextNoteToSpawn]->TeleportTo(FVector(x, y, z), FRotator());

				noteObjects[nextNoteToSpawn]->Activate();

				++nextNote;

				// Make sure we dont go over the max number of notes
				if (nextNote < weapons[selectedWeapon].notes.Num())
				{
					nextNoteTime = weapons[selectedWeapon].notes[nextNote] * weapons[selectedWeapon].secondsPerBeat;
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
			isGamePlaying = false;
		}
	}
}

void AAnvil::StartGame()
{
	// Set variables
	isGamePlaying = true;
	timePassed = 0.0f;
	score = 0.0f;

	nextNoteTime = weapons[selectedWeapon].notes[0] * weapons[selectedWeapon].secondsPerBeat;

	// Start song
	//weapons[selectedWeapon].song
}
