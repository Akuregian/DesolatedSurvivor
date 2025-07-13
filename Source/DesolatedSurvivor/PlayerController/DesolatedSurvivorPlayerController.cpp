// Copyright Epic Games, Inc. All Rights Reserved.


#include "DesolatedSurvivorPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "CameraManager/DesolatedSurvivorCameraManager.h"

ADesolatedSurvivorPlayerController::ADesolatedSurvivorPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ADesolatedSurvivorCameraManager::StaticClass();
}

void ADesolatedSurvivorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
