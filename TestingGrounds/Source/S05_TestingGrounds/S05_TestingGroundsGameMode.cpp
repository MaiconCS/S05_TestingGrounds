// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\S05_TestingGroundsGameMode.h"
#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\S05_TestingGroundsHUD.h"
#include "H:\repos\Unreal\S05_TestingGrounds\TestingGrounds\Source\S05_TestingGrounds\Player\FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_TestingGroundsGameMode::AS05_TestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TestingGroundsHUD::StaticClass();
}
