// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManagerRTS.h"

AGameManagerRTS::AGameManagerRTS()
{
	gameTime = 0.0f;
	goalAchieved = false;
}

void AGameManagerRTS::RegisterMainBuild(AActor* MainBuild)
{
	MainBuildActor = MainBuild;
}

void AGameManagerRTS::AddResources(int Amount)
{
	TotalResources += Amount;
	CheckWinConditions();
}

void AGameManagerRTS::CheckWinConditions()
{
	if (TotalResources >= TargetResources)
	{
		// Trigger win (BlueprintImplementableEvent or Broadcast)
		UE_LOG(LogTemp, Warning, TEXT("WIN CONDITION MET: resources"));
	}
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
