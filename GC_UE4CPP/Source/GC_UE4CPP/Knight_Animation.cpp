// Fill out your copyright notice in the Description page of Project Settings.


#include "Knight_Animation.h"

UKnight_Animation::UKnight_Animation()
{
	Speed = 0.0;
}

void UKnight_Animation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	const AActor* OwningActor = GetOwningActor();
	if (IsValid(OwningActor))
	{
		Speed = OwningActor->GetVelocity().Size();
	}
}

void UKnight_Animation::PlayVictoryAnimation()
{
	
	USkeletalMeshComponent* Mesh = GetSkelMeshComponent();
	if (IsValid(Mesh)) Mesh->PlayAnimation(VictoryAnim, false);
}
