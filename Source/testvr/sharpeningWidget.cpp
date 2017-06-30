// Fill out your copyright notice in the Description page of Project Settings.

#include "sharpeningWidget.h"


void UsharpeningWidget::Activate(float diff)
{
	isActive = true;
	currPositionRandomizer = mStream.FRand() * maxPositionRandomizer;
	difficulty = -diff;
	totalPenetration = 0.f;
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
	return 0.f;
}