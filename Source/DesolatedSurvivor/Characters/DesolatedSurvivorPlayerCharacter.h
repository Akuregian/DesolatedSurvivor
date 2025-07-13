// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Shooter/ShooterCharacter.h"
#include "AbilitySystemInterface.h"
#include "DesolatedSurvivorPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DESOLATEDSURVIVOR_API ADesolatedSurvivorPlayerCharacter : public AShooterCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ADesolatedSurvivorPlayerCharacter();

	/* IAbilitySystemInterface */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; };

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:

	/* Core GAS component */
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
};
