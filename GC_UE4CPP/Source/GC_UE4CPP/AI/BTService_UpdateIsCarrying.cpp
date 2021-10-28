// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_UpdateIsCarrying.h"

#include "AIControllerEnemy.h"
#include "BlackboardKeys.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTService_UpdateIsCarrying::UBTService_UpdateIsCarrying()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Update Is Carrying");
}

void UBTService_UpdateIsCarrying::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	Controller->GetBlackboardComponent()->SetValueAsBool(BBKeys::IsCarrying, Cast<AAIEnemyCharacter>(Controller->GetPawn())->bCarrying);
}

FString UBTService_UpdateIsCarrying::GetStaticServiceDescription() const
{
	return FString("Update the IsCarrying BB value");
}