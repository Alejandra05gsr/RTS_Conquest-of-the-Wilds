// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuildRTS.h"

// Sets default values
AMainBuildRTS::AMainBuildRTS()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMainBuildRTS::CreateWorker()
{
	if (WorkerClass)
	{
		FVector spawnPlace = GetActorLocation() + FVector(0, 0, 0);
		GetWorld()->SpawnActor<ACharacterRTS>(WorkerClass, spawnPlace, FRotator::ZeroRotator);
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

