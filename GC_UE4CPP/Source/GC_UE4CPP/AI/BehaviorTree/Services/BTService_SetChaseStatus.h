// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "GC_UE4CPP/AI/AIControllerEnemy.h"
#include "BTService_SetChaseStatus.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTService_SetChaseStatus : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_SetChaseStatus();
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticServiceDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EChaseStatus Enum;
};
