// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "KnightAnimation.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UKnightAnimation : public UAnimInstance
{
	GENERATED_BODY()

public:
	UKnightAnimation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bCarrying;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bVictory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bDefeat;

private:

public:
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	void PlayVictoryAnimation();
};
