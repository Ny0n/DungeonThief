// Fill out your copyright notice in the Description page of Project Settings.


#include "KnightAnimation.h"

UKnightAnimation::UKnightAnimation()
{
	Speed = 0.0;
}

void UKnightAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	const AActor* OwningActor = GetOwningActor();
	if (IsValid(OwningActor))
	{
		Speed = OwningActor->GetVelocity().Size();
	}
}

void UKnightAnimation::PlayVictoryAnimation()
{
	
	// USkeletalMeshComponent* Mesh = GetSkelMeshComponent();
	// if (IsValid(Mesh)) Mesh->PlayAnimation(VictoryAnim, false);
}
