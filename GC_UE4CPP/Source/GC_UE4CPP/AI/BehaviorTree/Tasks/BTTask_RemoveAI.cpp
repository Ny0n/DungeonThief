// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RemoveAI.h"

#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "GC_UE4CPP/AI/AIControllerEnemy.h"

UBTTask_RemoveAI::UBTTask_RemoveAI(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Remove AI");
}

EBTNodeResult::Type UBTTask_RemoveAI::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get references to AIController and NPC
	AGC_UE4CPPGameModeBase* GameModeBase = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode());

	// we destroy the AI and make the GameModeBase spawn a new one
	GameModeBase->RemoveAI();
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	Controller->GetPawn()->Destroy();
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}