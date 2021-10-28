// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DropFood.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/AIControllerEnemy.h"
#include "GC_UE4CPP/AI/BehaviorTree/BlackboardKeys.h"

UBTTask_DropFood::UBTTask_DropFood(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Drop Food");
}

EBTNodeResult::Type UBTTask_DropFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	AAIEnemyCharacter* NPC = Cast<AAIEnemyCharacter>(Controller->GetPawn());

	// before dropping the food, we keep a ref to it
	Controller->GetBlackboardComponent()->SetValueAsObject(BBKeys::DroppedFood, NPC->FoodActor);
	
	// drop food
	NPC->DropFood();
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
