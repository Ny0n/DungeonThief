// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinAnim.h"

UGoblinAnim::UGoblinAnim()
{
}

inline void UGoblinAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	GameModeBase = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode());
	Character = Cast<AAIEnemyCharacter>(TryGetPawnOwner());
}

void UGoblinAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// same as for the knight
	const AActor* OwningActor = GetOwningActor();
	if (OwningActor != nullptr)
		Speed = OwningActor->GetVelocity().Size();

	if (GameModeBase != nullptr && Character != nullptr)
	{
		bVictory = GameModeBase->bVictory;
		bDefeat = GameModeBase->bDefeat;
		bPlaying = GameModeBase->bPlaying;
		bCarrying = Character->bCarrying;
	}
}
