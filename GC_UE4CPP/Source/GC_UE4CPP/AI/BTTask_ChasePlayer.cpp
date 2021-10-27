// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChasePlayer.h"

#include "AIControllerEnemy.h"
#include "BlackboardKeys.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UBTTask_ChasePlayer::UBTTask_ChasePlayer(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UBTTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	const FVector PlayerLocation = Controller->GetBlackboardComponent()->GetValueAsVector(BBKeys::PlayerLocation);

	// move to the player's location
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, PlayerLocation);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
