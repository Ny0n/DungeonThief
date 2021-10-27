// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerEnemy.h"

#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BlackboardKeys.h"
#include "GC_UE4CPP/MainCharacter/MainCharacter.h"

AAIControllerEnemy::AAIControllerEnemy()
{
	SetupPerceptionSystem();
}

void AAIControllerEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	if (BTAsset != nullptr)
		RunBehaviorTree(BTAsset);
}

void AAIControllerEnemy::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if (Cast<AMainCharacter>(Actor))
	{
		Blackboard->SetValueAsBool(BBKeys::CanSeePlayer, Stimulus.WasSuccessfullySensed());
	}
}

void AAIControllerEnemy::SetupPerceptionSystem()
{
	// Create and set the perception component
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Component"));
	SetPerceptionComponent(*AIPerception);

	// Create and initialize the sight config object
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SightConfig->SightRadius = 800.0f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 50.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	SightConfig->SetMaxAge(3.0f);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = 0.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	// Add sight config to perception component
	GetPerceptionComponent()->SetDominantSense(SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AAIControllerEnemy::OnTargetDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}
