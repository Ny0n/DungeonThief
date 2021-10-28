// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/AIEnemyCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "Props/ActorReferencer.h"
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

	// Game state
	
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

	void Victory();
	void Defeat();
	void Play();
	void AddFood();

	// IA Management
	
	UPROPERTY()
	AActorReferencer* ActorReferencer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxFoodInGame = 5;

	void RemoveAI();

private:
	UPROPERTY()
	AInterfaceCreation* HUDBase;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TSubclassOf<class AAIEnemyCharacter> EnemyCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TSubclassOf<class APickUp> FoodBP;

	int ActiveAI = 0;
	int FoodNb = 0;
	
	void DropPlayerFood();
	void InitAI();
	void SpawnAI();
	void SpawnAIWithDelay(float Delay);
	void SpawnRandomFood();
};
