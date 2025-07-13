// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSet/DesolatedSurvivorHealthAttribute.h"
#include "GameplayEffectExtension.h"

void UDesolatedSurvivorHealthAttribute::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		OnHealthChangeEvent.Broadcast(Data.EvaluatedData.Magnitude, GetHealth());
	}
}
