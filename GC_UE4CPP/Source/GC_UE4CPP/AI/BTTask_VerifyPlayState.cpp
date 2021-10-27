// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_VerifyPlayState.h"

#include "AIControllerEnemy.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "Kismet/KismetStringLibrary.h"

UBTTask_VerifyPlayState::UBTTask_VerifyPlayState(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Verify Play State");
}

EBTNodeResult::Type UBTTask_VerifyPlayState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get references to AIController and NPC
	AGC_UE4CPPGameModeBase* GameModeBase = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode());
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, UKismetStringLibrary::Conv_BoolToString(GameModeBase->bPlaying));

	if (GameModeBase->bPlaying)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded); // Finish with success
	else
	{
		// We stop the AI's logic
		AAIControllerEnemy* Controller = Cast<AAIControllerEnemy>(OwnerComp.GetAIOwner());
		Controller->BrainComponent->StopLogic("Game Finished");
	}
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}