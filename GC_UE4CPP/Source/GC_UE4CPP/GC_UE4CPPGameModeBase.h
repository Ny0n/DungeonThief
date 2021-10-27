// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UI/InterfaceCreation.h"
#include "GC_UE4CPPGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AGC_UE4CPPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGC_UE4CPPGameModeBase();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	bool bVictory;
	
	UPROPERTY(BlueprintReadOnly)
	bool bDefeat;

	UPROPERTY(BlueprintReadOnly)
	bool bPlaying;

	UPROPERTY(EditAnywhere)
	float FoodMaxQuantity = 5.0;

	UPROPERTY(EditAnywhere)
	float FoodCurrentQuantity = 0.0;

	UPROPERTY()
	AInterfaceCreation* HUDBase;

	void Victory();
	void Defeat();
	void Play();
	void AddFood();
};
