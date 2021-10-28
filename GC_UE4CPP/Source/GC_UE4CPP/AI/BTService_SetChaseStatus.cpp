// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SetChaseStatus.h"

#include "BlackboardKeys.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_SetChaseStatus::UBTService_SetChaseStatus()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Set Chase Status");
}

void UBTService_SetChaseStatus::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	Controller->GetBlackboardComponent()->SetValueAsEnum(BBKeys::ChaseStatus, static_cast<uint8>(Enum));
}

FString UBTService_SetChaseStatus::GetStaticServiceDescription() const
{
	return FString("Change the BB ChaseStatus Enum");
}