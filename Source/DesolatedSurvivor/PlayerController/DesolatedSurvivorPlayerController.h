// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DesolatedSurvivorPlayerController.generated.h"

class UInputMappingContext;

/**
 *  Simple first person Player Controller
 *  Manages the input mapping context.
 *  Overrides the Player Camera Manager class.
 */
UCLASS(abstract)
class DESOLATEDSURVIVOR_API ADesolatedSurvivorPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	ADesolatedSurvivorPlayerController();

protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Input", meta = (AllowPrivateAccess = "true"))
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

};
