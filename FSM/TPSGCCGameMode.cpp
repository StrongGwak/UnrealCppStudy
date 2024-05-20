// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPSGCCGameMode.h"
#include "TPSGCCCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPSGCCGameMode::ATPSGCCGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
