// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Knight_Animation.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UKnight_Animation : public UAnimInstance
{
	GENERATED_BODY()

public:
	UKnight_Animation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bCarrying;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bVictory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bDefeat;

private:

public:
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	void PlayVictoryAnimation();
};
