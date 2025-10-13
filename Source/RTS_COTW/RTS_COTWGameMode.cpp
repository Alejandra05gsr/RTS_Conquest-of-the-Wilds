// Copyright Epic Games, Inc. All Rights Reserved.

#include "RTS_COTWGameMode.h"
#include "RTS_COTWPlayerController.h"
#include "RTS_COTWCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARTS_COTWGameMode::ARTS_COTWGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARTS_COTWPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}