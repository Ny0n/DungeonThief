// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
};
