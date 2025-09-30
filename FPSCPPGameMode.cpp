// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPSCPPGameMode.h"
#include "FPSCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSCPPGameMode::AFPSCPPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
