// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuildRTS.h"
#include "Engine/World.h"
#include "CharacterRTS.h"

// Sets default values
AMainBuildRTS::AMainBuildRTS()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


ACharacterRTS* AMainBuildRTS::CreateWorker()
{
    if (!WorkerClass) return nullptr;

    FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 200.f; // ajustar
    FRotator SpawnRot = GetActorRotation();

    FActorSpawnParameters Params;
    Params.Owner = this;

    ACharacterRTS* NewUnit = GetWorld()->SpawnActor<ACharacterRTS>(UnitClassToSpawn, SpawnLocation, SpawnRot, Params);
    if (NewUnit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Spawned unit: %s"), *NewUnit->GetName());
    }
    return nullptr;
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

