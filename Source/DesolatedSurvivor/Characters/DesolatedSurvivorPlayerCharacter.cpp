// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DesolatedSurvivorPlayerCharacter.h"

ADesolatedSurvivorPlayerCharacter::ADesolatedSurvivorPlayerCharacter()
{
	/* 'Player' Tag is used for Enemy AI, without it the enemy won't look for you */
	Tags.Add(FName("Player"));
}

void ADesolatedSurvivorPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
