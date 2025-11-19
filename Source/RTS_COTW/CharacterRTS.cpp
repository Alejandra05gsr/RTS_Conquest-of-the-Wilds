// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterRTS.h"
#include "AIControllerRTS.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACharacterRTS::ACharacterRTS()
{
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AAIControllerRTS::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bIsSelected = false;
	CarryAmount = 0;

}

void ACharacterRTS::SetUnitType(EUnitType newType)
{
	switch (UnitType)
	{
	case EUnitType::Worker:
		health = 50.0f;
		attack = 0.0f;
		speed = 10.0f;

		break;
	case EUnitType::Warrior:
		health = 100.0f;
		attack = 20.0f;
		speed = 15.0f;
		break;
	case EUnitType::Archer:
		health = 150.0f;
		attack = 40.0f;
		speed = 5.0f;
		break;
	}

	GetCharacterMovement()->MaxWalkSpeed = speed;

}

void ACharacterRTS::MoveToLocation(const FVector& Destination)
{
	AAIControllerRTS* AICon = Cast<AAIControllerRTS>(GetController());

	if (AICon)
	{
		AICon->CharacterMove(Destination);
	}
}

// Called when the game starts or when spawned
void ACharacterRTS::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACharacterRTS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterRTS::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}





