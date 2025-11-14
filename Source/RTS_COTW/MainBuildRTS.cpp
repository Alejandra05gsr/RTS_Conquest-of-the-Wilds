// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuildRTS.h"

// Sets default values
AMainBuildRTS::AMainBuildRTS()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void AMainBuildRTS::CreateWorker(float posX, float posY, float posZ)
{
	if (WorkerClass)
	{
		UWorld* world = GetWorld();
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			FRotator rotator;
			FVector spawnLocation(posX, posY, posZ);

			world->SpawnActor<ACharacterRTS>(WorkerClass, spawnLocation, rotator, spawnParams);
		}
	}
}

// Called when the game starts or when spawned
void AMainBuildRTS::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMainBuildRTS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

