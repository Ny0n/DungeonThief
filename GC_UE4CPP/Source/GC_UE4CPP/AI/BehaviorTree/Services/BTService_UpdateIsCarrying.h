// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_UpdateIsCarrying.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTService_UpdateIsCarrying : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_UpdateIsCarrying();
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticServiceDescription() const override;
	
};
