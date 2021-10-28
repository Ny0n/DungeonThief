// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIEnemyCharacter.h"
#include "Animation/AnimInstance.h"
#include "GC_UE4CPP/GC_UE4CPPGameModeBase.h"
#include "GoblinAnim.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UGoblinAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	UGoblinAnim();
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 0.0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bVictory = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDefeat = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bPlaying = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCarrying = false;

private:
	UPROPERTY()
	AGC_UE4CPPGameModeBase* GameModeBase;
	
	UPROPERTY()
	AAIEnemyCharacter* Character;
	
};
