// Fill out your copyright notice in the Description page of Project Settings.

#include "sharpeningWidget.h"


void UsharpeningWidget::Activate(float diff)
{
	isActive = true;
	float currPositionRandomizer = mStream.FRand() * maxPositionRandomizer;
	difficulty = -diff;
	totalPenetration = 0.f;

	mLeftWidgetPosition = currPositionRandomizer + 50;
	mRightWidgetPosition = currPositionRandomizer + 450 + difficulty;
	
}

void UsharpeningWidget::Deactivate()
{
	isActive = false;
}

void UsharpeningWidget::AddPenetration(float pen)
{
	totalPenetration += pen * penetrationMultiplier;
}

float UsharpeningWidget::GetQuality()
{
	float startGreenPoint = 960.f + mLeftWidgetPosition + 66.66f;
	float endGreenPoint = 960.f + mRightWidgetPosition - 66.66f;

	float startYellowPoint = startGreenPoint - 140.0f;
	float endYellowPoint = endGreenPoint + 140.0f;
	

	if (totalPenetration >= startYellowPoint && totalPenetration < startGreenPoint)
	{
		return (totalPenetration - startYellowPoint) / (startGreenPoint - startYellowPoint);
	}

	else if (totalPenetration >= startGreenPoint && totalPenetration <= endGreenPoint)
	{
		return 1.f;
	}

	else if (totalPenetration > endGreenPoint && totalPenetration <= endYellowPoint)
	{
		return 1.f + (totalPenetration - endGreenPoint) / (endYellowPoint - endGreenPoint);
	}

	return 0.f;
}