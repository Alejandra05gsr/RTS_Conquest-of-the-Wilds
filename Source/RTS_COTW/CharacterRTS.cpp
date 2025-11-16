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
	UnitState = EUnitState::Idle;
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

void ACharacterRTS::OnMoveFinishedByController()
{

	if (UnitState == EUnitState::Moving)
	{
		UnitState = EUnitState::Idle;
		if (TargetResource)
		{
			UnitState = EUnitState::Gathering;
		}
	}
	else if (UnitState == EUnitState::Returning)
	{
		AGameModeBase* GM = UGameplayStatics::GetGameMode(this);
		UnitState = EUnitState::Idle;
		CarryAmount = 0;
	}
	else if (UnitState == EUnitState::Fleeing)
	{
		UnitState = EUnitState::Idle;
	}
}

void ACharacterRTS::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor) return;

	if (OtherActor->ActorHasTag("Enemy"))
	{
		if (UnitType == EUnitType::Worker)
		{
			UnitState = EUnitState::Fleeing;
			AGameModeBase* GM = UGameplayStatics::GetGameMode(this);
		}
	}
}


void ACharacterRTS::StartGather(AActor* ResourceActor)
{
	if (!ResourceActor) return;
	TargetResource = ResourceActor;
	UnitState = EUnitState::Moving;
	MoveToLocation(TargetResource->GetActorLocation());
}

// Called when the game starts or when spawned
void ACharacterRTS::BeginPlay()
{
	Super::BeginPlay();


	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ACharacterRTS::OnBeginOverlap);

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





