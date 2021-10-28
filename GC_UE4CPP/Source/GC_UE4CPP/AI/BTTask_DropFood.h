// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_DropFood.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTTask_DropFood : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_DropFood(const FObjectInitializer& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
