// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AIControllerEnemy.generated.h"

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

	UPROPERTY(EditAnywhere)
	UBehaviorTree* BTAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAIPerceptionComponent* AIPerception;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAISenseConfig_Sight* SightConfig;
	
private:
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);

	void SetupPerceptionSystem();
};
