// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "testvrHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

AtestvrHUD::AtestvrHUD()
{
	// Set the crosshair texture

}


void AtestvrHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);


}
