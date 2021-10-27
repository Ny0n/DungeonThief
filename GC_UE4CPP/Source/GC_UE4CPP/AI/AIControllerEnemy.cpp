// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerEnemy.h"

AAIControllerEnemy::AAIControllerEnemy()
{
	
}

void AAIControllerEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	if (BTAsset != nullptr)
		RunBehaviorTree(BTAsset);
}
