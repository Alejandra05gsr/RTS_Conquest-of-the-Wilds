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


ACharacterRTS* AMainBuildRTS::CreateWarrior(float Posx, float Posy, float Posz, float Rotz)
{
    if (!WarriorClass)
    {
        UE_LOG(LogTemp, Error, TEXT("WorkerClass no está asignado en el Blueprint!"));
        return nullptr;
    }

    FVector SpawnLocation(Posx, Posy, Posz);
    FRotator SpawnRot(0.f, Rotz, 0.f);

    FActorSpawnParameters Params;
    Params.Owner = this;

    ACharacterRTS* NewUnit = GetWorld()->SpawnActor<ACharacterRTS>(
        WarriorClass,
        SpawnLocation,
        SpawnRot,
        Params
    );

    if (NewUnit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Warrior creado correctamente!"));
    }
    else
    {

        UE_LOG(LogTemp, Error, TEXT("ERROR: No se pudo crear el warrior."));
    }

    return NewUnit;
}

ACharacterRTS* AMainBuildRTS::CreateWorker(float Posx, float Posy, float Posz, float Rotz)
{
    if (!WorkerClass)
    {
        UE_LOG(LogTemp, Error, TEXT("WorkerClass no está asignado en el Blueprint!"));
        return nullptr;
    }

    FVector SpawnLocation(Posx, Posy, Posz);
    FRotator SpawnRot(0.f, Rotz, 0.f);

    FActorSpawnParameters Params;
    Params.Owner = this;

    ACharacterRTS* NewUnit = GetWorld()->SpawnActor<ACharacterRTS>(
        WorkerClass,
        SpawnLocation,
        SpawnRot,
        Params
    );

    if (NewUnit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Worker creado correctamente!"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ERROR: No se pudo crear el worker."));
    }

    return NewUnit;
 
}


ACharacterRTS* AMainBuildRTS::CreateWizard(float Posx, float Posy, float Posz, float Rotz)
{
    if (!WizardClass)
    {
        UE_LOG(LogTemp, Error, TEXT("WizardClass no está asignado en el Blueprint!"));
        return nullptr;
    }

    FVector SpawnLocation(Posx, Posy, Posz);
    FRotator SpawnRot(0.f, Rotz, 0.f);

    FActorSpawnParameters Params;
    Params.Owner = this;

    ACharacterRTS* NewUnit = GetWorld()->SpawnActor<ACharacterRTS>(
        WizardClass,
        SpawnLocation,
        SpawnRot,
        Params
    );

    if (NewUnit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Wizard creado correctamente!"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ERROR: No se pudo crear el wizard."));
    }

    return NewUnit;
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

