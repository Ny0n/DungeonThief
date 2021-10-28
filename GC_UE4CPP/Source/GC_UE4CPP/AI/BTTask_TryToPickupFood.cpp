// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TryToPickupFood.h"

#include "AIControllerEnemy.h"
#include "BlackboardKeys.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TryToPickupFood::UBTTask_TryToPickupFood(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Try to Pickup Food");
}

EBTNodeResult::Type UBTTask_TryToPickupFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	AAIEnemyCharacter* NPC = Cast<AAIEnemyCharacter>(Controller->GetPawn());

	// Get the food
	APickUp* DroppedFood = Cast<APickUp>(Controller->GetBlackboardComponent()->GetValueAsObject(BBKeys::DroppedFood));

	if (!DroppedFood->GetIsPickUP())
	{
		NPC->PickupFood(DroppedFood);
	}
	
	// we got it, so we can clear the BB value to return to normal behavior
	Controller->GetBlackboardComponent()->ClearValue(BBKeys::DroppedFood);
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}