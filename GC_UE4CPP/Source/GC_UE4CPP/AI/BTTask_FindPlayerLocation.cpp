// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPlayerLocation.h"

#include "AIControllerEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/MainCharacter/MainCharacter.h"
#include "BlackboardKeys.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindPlayerLocation::UBTTask_FindPlayerLocation(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AMainCharacter* Player = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());

	// Set the location to the blackboard key to communicate to the BT
	Controller->GetBlackboardComponent()->SetValueAsVector(BBKeys::PlayerLocation, Player->GetActorLocation());
	Controller->GetBlackboardComponent()->SetValueAsRotator(BBKeys::PlayerRotation, Player->GetActorRotation());
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
