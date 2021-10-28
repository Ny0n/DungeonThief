// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TryToDepositFood.h"

#include "AIControllerEnemy.h"
#include "BlackboardKeys.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TryToDepositFood::UBTTask_TryToDepositFood(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Try to Deposit Food");
}

EBTNodeResult::Type UBTTask_TryToDepositFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	AAIEnemyCharacter* NPC = Cast<AAIEnemyCharacter>(Controller->GetPawn());

	// Get the food spot
	ASpotFood* FoodSpot = Cast<ASpotFood>(Controller->GetBlackboardComponent()->GetValueAsObject(BBKeys::FoodSpot));

	if (!FoodSpot->GetHaveFood())
	{
		NPC->DropFoodOnSpot(FoodSpot);
	}
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}