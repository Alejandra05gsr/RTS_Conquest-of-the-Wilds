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
	Archer UMETA(DisplayName = "Archer"),
	Wizard UMETA(DisplayName = "Wizard")
};

UENUM(BlueprintType)
enum class EUnitState : uint8
{
	Idle,
	Moving,
	Gathering,
	Returning,
	Fleeing
};

UCLASS()
class RTS_COTW_API ACharacterRTS : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterRTS();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS")
	EUnitType UnitType;

	// Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS")
	float health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS")
	float attack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS")
	float speed;

	//Function
	UFUNCTION(BlueprintCallable)
	void SetUnitType(EUnitType newType);


	UFUNCTION(BlueprintCallable)
	void MoveToLocation(const FVector& Destination);


	UPROPERTY(BlueprintReadWrite)
	AActor* TargetResource;

	UPROPERTY(BlueprintReadWrite)
	int32 CarryAmount;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsSelected;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
