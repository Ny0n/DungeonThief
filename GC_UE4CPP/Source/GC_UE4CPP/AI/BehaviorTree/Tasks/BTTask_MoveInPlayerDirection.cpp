// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveInPlayerDirection.h"

#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GC_UE4CPP/AI/AIControllerEnemy.h"
#include "GC_UE4CPP/AI/BehaviorTree/BlackboardKeys.h"

UBTTask_MoveInPlayerDirection::UBTTask_MoveInPlayerDirection(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Move in Player Direction");
}

EBTNodeResult::Type UBTTask_MoveInPlayerDirection::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	AAIEnemyCharacter* NPC = Cast<AAIEnemyCharacter>(Controller->GetPawn());

	// We get the last direction of the player
	FRotator PlayerRotation = Controller->GetBlackboardComponent()->GetValueAsRotator(BBKeys::PlayerRotation);

	// We find a position to move to in accordance with the rotation, and go to it (for 3 secs, the BT is taking care of that)
	NPC->SetActorRotation(PlayerRotation);
	FVector NewTargetLocation = NPC->GetActorLocation() + NPC->GetActorForwardVector() * Distance;
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, NewTargetLocation);
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
