// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerRTS.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "CharacterRTS.h"

void AAIControllerRTS::CharacterMove(const FVector& EndPos)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, EndPos);
}

void AAIControllerRTS::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    Super::OnMoveCompleted(RequestID, Result);

    APawn* P = GetPawn();
    if (!P) return;

    ACharacterRTS* CRTS = Cast<ACharacterRTS>(P);
    if (CRTS)
    {
        CRTS->OnMoveFinishedByController(); // implementaremos en CharacterRTS
    }
}
