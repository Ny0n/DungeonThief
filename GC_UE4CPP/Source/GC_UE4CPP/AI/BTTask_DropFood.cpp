// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DropFood.h"

#include "AIControllerEnemy.h"

UBTTask_DropFood::UBTTask_DropFood(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Drop Food");
}

EBTNodeResult::Type UBTTask_DropFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	AAIEnemyCharacter* NPC = Cast<AAIEnemyCharacter>(Controller->GetPawn());
	
	// drop food
	NPC->DropFood(); // UPDATE DroppedFood BB KEY // DISABLE COLLISION AVEC FOOD
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}