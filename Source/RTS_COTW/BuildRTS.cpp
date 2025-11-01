// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildRTS.h"

// Sets default values
ABuildRTS::ABuildRTS()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABuildRTS::CreateBuilding()
{
	switch (BuildType)
	{
	case EBuildType::Farm:
		maxCharacters = 10;
		productionBoost = 10.0f;
		break;
	case EBuildType::Stables:
		productionTime = 5.0f;
		break;
	case EBuildType::Barracks:
		productionTime = 10.0f;
		break;
	}
}

// Called when the game starts or when spawned
void ABuildRTS::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABuildRTS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

