// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DesolatedSurvivorPlayerCharacter.h"
#include "AttributeSet/DesolatedSurvivorHealthAttribute.h"
#include "Shooter/ShooterWeapon.h"
#include "GameplayTagContainer.h"

ADesolatedSurvivorPlayerCharacter::ADesolatedSurvivorPlayerCharacter()
{
	/* 'Player' Tag is used for Enemy AI, without it the enemy won't look for you */
	Tags.Add(FName("Player"));

	/* Create GAS Componenet */
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	/* create the Health Attribute */
	HealthAttribute = CreateDefaultSubobject<UDesolatedSurvivorHealthAttribute>(TEXT("HealthAttribute"));
}

void ADesolatedSurvivorPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HealthAttribute)
	{
		HealthAttribute->OnHealthChangeEvent.AddDynamic(this, &ADesolatedSurvivorPlayerCharacter::OnHealthChanged);
	}
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AbilitySystemComponent->SetNumericAttributeBase(UDesolatedSurvivorHealthAttribute::GetHealthAttribute(), InitialHealth);
	}
}

void ADesolatedSurvivorPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADesolatedSurvivorPlayerCharacter::OnHealthChanged(float Magnitude, float NewHealth)
{
	/* Check if helath is less than or equal to 0 */
	if (NewHealth <= 0.0f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString(TEXT("You have no health left!")));

		/* if weapon is active */
		if (CurrentWeapon)
		{
			/* deactivate it */
			CurrentWeapon->DeactivateWeapon();
		}

		/* Reset UI Bullet Counter to 0,0 */
		OnBulletCountUpdated.Broadcast(0, 0);

		//TODO: Destroy the character, doing GetOwner->Destroy Crashes the engine!
		/* Destroy the player */
		//GetOwner()->Destroy();
	}
}

void ADesolatedSurvivorPlayerCharacter::DumpActiveTagsOnASC(FColor TextColor)
{
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("[DebugPrintTags] No ASC found."));
		return;
	}

	// 1. Gather owned tags
	FGameplayTagContainer OwnedTags;
	AbilitySystemComponent->GetOwnedGameplayTags(OwnedTags);

	// 2. Convert to a single-line string
	//    e.g. "Survival.Ability.Weapon.StartFiring,Status.Poisoned"
	FString TagsString = OwnedTags.ToStringSimple();

	// 3. On-screen debug: use a constant message key so we don't spam multiple lines
	static const int32 DebugMsgKey = 1338;
	const float DisplayTime = 1.5f; // seconds

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			DebugMsgKey,
			DisplayTime,
			TextColor,
			FString::Printf(TEXT("%s ActiveTags: %s"), *GetOwner()->GetName(), *TagsString)
		);
	}
}
