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


ACharacterRTS* AMainBuildRTS::CreateWorker(float Posx, float Posy, float Posz, float Rotx, float Roty, float Rotz)
{
    if (!WorkerClass) return nullptr;

    FVector SpawnLocation (Posx,Posy,Posz); 
    FRotator SpawnRot(Rotx, Roty, Rotz);

    FActorSpawnParameters Params;
    Params.Owner = this;

    ACharacterRTS* NewUnit = (ACharacterRTS*)GetWorld()->SpawnActor<ACharacterRTS>(ACharacterRTS::StaticClass(), SpawnLocation, SpawnRot, Params);
 
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

