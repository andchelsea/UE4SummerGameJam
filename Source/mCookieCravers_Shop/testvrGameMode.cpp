// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "testvrGameMode.h"
#include "testvrHUD.h"
#include "testvrCharacter.h"
#include "UObject/ConstructorHelpers.h"

AtestvrGameMode::AtestvrGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/VRPlayerBlueprint"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AtestvrHUD::StaticClass();
}
