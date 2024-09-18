// Copyright Epic Games, Inc. All Rights Reserved.

#include "FactoryGameGameMode.h"
#include "FactoryGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFactoryGameGameMode::AFactoryGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
