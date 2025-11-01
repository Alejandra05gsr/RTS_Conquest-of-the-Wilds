// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManagerRTS.h"

AGameManagerRTS::AGameManagerRTS()
{
	gameTime = 0.0f;
	goalAchieved = false;
}

void AGameManagerRTS::CheckTime(float dTime)
{
	gameTime += dTime;
	CheckObjective();
}

void AGameManagerRTS::CheckObjective()
{
	if (Buildings.Num() >= 6 && gameTime <= 300)
	{
		goalAchieved = true;
	}
}
