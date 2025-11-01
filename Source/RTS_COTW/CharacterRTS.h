// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterRTS.generated.h"

UENUM(BlueprintType)
enum class EUnitType : uint8
{
	Worker UMETA(DisplayName = "Worker"),
	Warrior UMETA(DisplayName = "Warrior"),
	Archer UMETA(DisplayName = "Archer")
};


UCLASS()
class RTS_COTW_API ACharacterRTS : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterRTS();

	EUnitType UnitType;

	//Attributes
	float health;
	float attack;
	float speed;

	//Function
	void SetUnitType(EUnitType newType);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
