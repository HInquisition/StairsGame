// Copyright Epic Games, Inc. All Rights Reserved.

#include "UserTexturesTesterGameMode.h"
#include "UserTexturesTesterHUD.h"
#include "UserTexturesTesterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUserTexturesTesterGameMode::AUserTexturesTesterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUserTexturesTesterHUD::StaticClass();
}
