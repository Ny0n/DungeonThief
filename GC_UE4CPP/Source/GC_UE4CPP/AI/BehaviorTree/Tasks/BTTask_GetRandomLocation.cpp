// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRandomLocation.h"

#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/AIControllerEnemy.h"

UBTTask_GetRandomLocation::UBTTask_GetRandomLocation(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Get Random Location");
}

EBTNodeResult::Type UBTTask_GetRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get references to AIController and NPC
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
	APawn* NPC = Controller->GetPawn();
	FVector Origin = NPC->GetActorLocation();

	// Find a new location on the NavMesh
	FVector RandomLocation = UNavigationSystemV1::GetRandomPointInNavigableRadius(GetWorld(), Origin, SearchRadius);

	// Set the location to the blackboard key to communicate to the BT
	Controller->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, RandomLocation);

	// Finish with success
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
