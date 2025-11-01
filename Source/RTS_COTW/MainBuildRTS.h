// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterRTS.h"
#include "MainBuildRTS.generated.h"

UCLASS()
class RTS_COTW_API AMainBuildRTS : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMainBuildRTS();

	TSubclassOf<ACharacterRTS> WorkerClass;

	void CreateWorker();




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
