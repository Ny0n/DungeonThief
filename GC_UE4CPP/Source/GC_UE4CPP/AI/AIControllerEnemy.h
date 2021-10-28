// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AIControllerEnemy.generated.h"

UENUM(BlueprintType)
enum class EChaseStatus : uint8 { Patrolling, Searching, Chasing };

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAIControllerEnemy : public AAIController
{
	GENERATED_BODY()

public:
	AAIControllerEnemy();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	AGC_UE4CPPGameModeBase* GameModeBase;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BTAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAIPerceptionComponent* AIPerception;

	UPROPERTY()
	UAISenseConfig_Sight* SightConfig;
	
private:
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);

	void SetupPerceptionSystem();
};
