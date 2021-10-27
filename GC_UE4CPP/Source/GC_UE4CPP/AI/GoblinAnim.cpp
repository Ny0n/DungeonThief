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

	const AActor* OwningActor = GetOwningActor();
	if (IsValid(OwningActor))
	{
		Speed = OwningActor->GetVelocity().Size();
	}

	if (IsValid(GameModeBase) && IsValid(Character))
	{
		bVictory = GameModeBase->bVictory;
		bDefeat = GameModeBase->bDefeat;
		bPlaying = GameModeBase->bPlaying;
		// bCarrying = Character->bCarrying;
	}
}