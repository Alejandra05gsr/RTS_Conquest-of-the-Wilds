// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterRTS.h"
#include "BuildRTS.generated.h"

UENUM(BlueprintType)
enum class EBuildType : uint8
{
	Barracks UMETA(DisplayName = "Barracks"),
	Farm UMETA(DisplayName = "Farm"),
	Stables UMETA(DisplayName = "Stables")
};


UCLASS()
class RTS_COTW_API ABuildRTS : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildRTS();

	EBuildType BuildType;

	void CreateBuilding();


	FString buildingName;
	float hpBuilding;
	float buildTime;
	int costWood;
	int costStone;
	int costGold;
	bool isBuilded;
	bool spawnWarriors;


	//Farm
	int maxCharacters; 	//Numero limite de criaturas permitidas en ese bando
	float productionBoost;

	//Barracks, Stables
	float productionTime;






protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
