// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet/DesolatedSurvivorBase_AttributeSet.h"
#include "DesolatedSurvivorHealthAttribute.generated.h"

/**
 * 
 */
UCLASS()
class DESOLATEDSURVIVOR_API UDesolatedSurvivorHealthAttribute : public UDesolatedSurvivorBase_AttributeSet
{
	GENERATED_BODY()

public:
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY()
	FActivateAttributeEvent OnHealthChangeEvent;

	UPROPERTY()
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDesolatedSurvivorHealthAttribute, Health)
};
