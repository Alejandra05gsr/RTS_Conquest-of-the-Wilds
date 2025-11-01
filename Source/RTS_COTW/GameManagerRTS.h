// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterRTS.h"
#include "BuildRTS.h"
#include "GameManagerRTS.generated.h"

/**
 *
 */
UCLASS()
class RTS_COTW_API AGameManagerRTS : public AGameModeBase
{
	GENERATED_BODY()



public:

	AGameManagerRTS();

	TArray<ACharacterRTS*> Characters;
	TArray<ABuildRTS*> Buildings;

	float gameTime;
	bool goalAchieved;

	void CheckTime(float dTime);
	void CheckObjective();


};
